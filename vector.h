#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include "main.h"

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
        typedef T *const_iterator;
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

        void assign(std::initializer_list<T> il){
            n = static_cast<std::size_t>(il.size());
            cap = static_cast<std::size_t>(il.size());
            elem = new T[il.size()];
            std::move(il.begin(), il.end(), elem);
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

        bool empty()const noexcept{
            if (n!=0) return true;
            else return false;
        }

        void reserve(size_t a){
            resize(a);
        }

        void shrink_to_fit(){
            if(n == cap) return;
            T* new_arr = new T[n];
            std::move(&elem[0], &elem[n], new_arr);
            cap = n;
            delete[] elem;
            elem = new_arr;
        }

        T& operator[](int i){
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

        const_reference at(size_t pos)const {
            if ((pos < 0) || (pos >= n)) {
                cout << "Error: you are out of array" << endl;
                exit(1);
            }
            return elem[pos];
        }

        T& front() {
            return elem[0];
        }

        const_reference front() const {
            return elem[0];
        }

        T& back() {
            return elem[n-1];
        }

        const_reference back() const {
            return elem[n-1];
        }

       /* T* data() noexcept{
            return elem;
        }*/

        T* begin() {
            if (n == 0) cout << "empty vector" << endl;
            return elem;
        }

        const_iterator begin()const {
            if (n == 0) cout << "empty vector" << endl;
            return elem;
        }

        T* end() {
            if (n == 0) cout << "empty vector" << endl;
            auto a = elem + n;
            return a;
        }

        const_iterator end()const {
            if (n == 0) cout << "empty vector" << endl;
            auto a = elem + n;
            return a;
        }

        const_iterator cbegin()const {
            if (n == 0) cout << "empty vector" << endl;
            return elem;
        }
        const_iterator cend()const {
            if (n == 0) cout << "empty vector" << endl;
            auto a = elem + n;
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

        T* insert(iterator pos, const T & a) {
            insert(pos, 1, a);
            return pos;
        }

        T* insert(iterator pos, size_t b, const T & a) {
            if (pos > elem + n) cout << "Error: you are out of array" << endl;
            for(int i = 0; i < b; i++){
                //auto it = pos;
                if (n >= cap) {
                    resize(n * 2);
                    pos = elem;
                    //it = elem;
                }
                n++;
                std::move(pos, pos + n, pos + 1);
                *pos = a;
                pos++;
            }
            return pos;
        }

        void insert(iterator pos, std::initializer_list<T> il){
            if(n+il.size() >= cap){
                resize(n + il.size() * 2);
                pos = elem;
            }
            std::move(pos, pos + n, pos + il.size());
            n += il.size();
            std::move(il.begin(), il.end(), pos);
        }

        void erase(int i){
            if (i < 0 || size() <= i)  {
                cout << "Error: you are out of array" << endl;
                return;
            }
            std::move(&elem[i+1], &elem[n], &elem[i]);
            n--;
        }

        void clear() {
            n = 0;
            delete[] elem;
            elem = new T[cap];
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