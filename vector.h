#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <algorithm>
#include <stdexcept>

namespace vec{

    template < typename T >
    class vector;

    template < typename T >
    bool operator== (const vector <T>&, const vector <T>&);

    template < typename T >
    bool operator!= (const vector <T>&, const vector <T>&);

    template <typename T >
    class vector {
    private:
        T *elem;
        size_t cap;
        size_t n;
    public:
        typedef T *iterator;
        typedef T &reference;
        typedef T &const_reference;

        vector() : n{ 0 },elem{ new T[1] }, cap{ 0 } {};
        vector(size_t n, T val) : n{ n }, elem{ new T[n] }, cap{ n } { std::fill_n(elem, n, val); }
        vector(size_t n) : n{ n }, elem{ new T[n] }, cap{ n } {};
        vector(std::initializer_list<T> il)
                : n{ static_cast<std::size_t>(il.size()) },
                  cap{ static_cast<std::size_t>(il.size()) },
                  elem{ new T[il.size()] } {
            std::copy(il.begin(), il.end(), elem);
        }
        ~vector() { delete[] elem; };

        vector& operator= (const vector& v){
            if(&v == this) return *this;
            T *p = new T[v.n];
            for(int i = 0; i != v.n; i++) p[i] = v.elem[i];
            delete[] elem;
            elem = p;
            n = v.n;
            return *this;
        }

        vector& operator= (const vector&& v){
            if(&v == this) return *this;
            delete[] elem;
            elem = v.elem;
            n = v.n;
            v.elem = nullptr;
            v.n = 0;
            return *this;
        }

        void assign(size_t count, const T& val) {
            assign(0, count, val);
        }

        void assign(size_t first, size_t last, const T& val) {
            n = last;
            for (size_t i = first; (i < last) && (i < n); i++)
                elem[i] = val;
        }

        int size() const { return n; }

       void resize(size_t sz) {
            if (sz <= cap) return;
            T* new_arr = new T[sz];
            for(int i = 0; i < cap; ++i) {
                new_arr[i] = elem[i];
            }
            cap = sz;
            delete[] elem;
            elem = new_arr;
        }

        int capacity() const { return cap; }

        bool empty(){
            if (n!=0) return true;
            else return false;
        }

        void reserve(size_t a){
            resize(a);
        }

        reference operator[](int i){
            if (i < 0 || size() <= i) cout << "Error: you are out of array" << endl;
            return elem[i];
        }

        const_reference operator[](int i)const{
            if (i < 0 || size() <= i) cout << "Error: you are out of array" << endl;
            return elem[i];
        }

        T& at(size_t pos) {
            if ((pos < 0) || (pos >= n)) {
                cout << "Error: you are out of array" << endl;
                exit(1);
            }
            return elem[pos];
        }
        T& front() const {
            return elem[0];
        }
        T& back() const {
            return elem[n-1];
        }

        iterator begin() {
            if (n == 0) cout << "empty vector" << endl;
            return elem;
        }
        iterator end() {
            if (n == 0) cout << "empty vector" << endl;
            auto a = elem + n; // - 1
            return a;
        }

        void push_back(double x) {
            if (n >= cap) resize(2 * n);
            elem[n] = x;
            n++;
        }

        void push_front(double x) {
            if (n >= cap) resize(2 * n);
            n++;
            std::move(&elem[0], &elem[n-1], &elem[1]);
            elem[0] = x;
        }

        void pop_back() {
            if (!n)
                return;
            else
                n--;
        }

        void insert(int i, double x) {
            insert(i, 1, x);
        }

        void insert(int i, int b, double x) {
            if (i < 0 || i > n) std::out_of_range("range error");
            for(int a = 0; a < b; a++){
                push_back(0);
                for(int j = n - 1; j > i; j--) {
                    elem[j] = elem[j - 1];
                }
                elem[i] = x;
                i++;
            }
        }

        T* insert(iterator it, const T & a) {
            if (it > elem + n) cout << "Error: you are out of array" << endl;
           // if (n >= cap) resize(2 * n);
            n++;
            std::move(it, it + n, it + 1);
            *it = a;
            return it;
        }

        void erase(int i){
            if (i < 0 || size() <= i)  {
                cout << "Error: you are out of array" << endl;
                return;
            }
            std::move(&elem[i+1], &elem[n], &elem[i]);
            n--;
        }

        friend bool operator== <T> (const vector <T>& left, const vector <T>& right);
        friend bool operator!= <T> (const vector <T>& left, const vector <T>& right);

    };

    template < typename T >
    bool operator== (const vector <T>& left, const vector <T>& right) {
        if (left.n != right.n)return false;
        else
            for (int i = 0; i < left.n; ++i)
                if (left[i] != right[i])return false;
        return true;
    }

    template < typename T >
    bool operator!= (const vector <T>& left, const vector <T>& right) {
        return !(left == right);
    }

}


#endif //VECTOR_VECTOR_H