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

    template < typename T >
    bool operator< (const vector <T>&, const vector <T>&);

    template < typename T >
    bool operator> (const vector <T>&, const vector <T>&);

    template < typename T >
    bool operator<= (const vector <T>&, const vector <T>&);

    template < typename T >
    bool operator>= (const vector <T>&, const vector <T>&);

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
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

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

       iterator resize(size_t sz, iterator it = 0) {
            if (sz <= cap) return it;
            T* new_arr = new T[sz];
            if(sz < n){
                cap = sz;
                n = sz;
            }
           auto pos = it - begin();
            for(int i = 0; i < cap; ++i) {
                new_arr[i] = elem[i];
            }
            cap = sz;
            delete[] elem;
            elem = new_arr;
            return begin() + pos;
        }

        int capacity() const { return cap; }

        bool empty()const noexcept{
            if (n==0) return true;
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

        T* data() noexcept{
            return elem;
        }

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

        reverse_iterator rbegin() {
            return reverse_iterator(end());
        }

        reverse_iterator rend() {
            return reverse_iterator(begin());
        }

        const_reverse_iterator crbegin()const {
            return reverse_iterator(end());
        }

        const_reverse_iterator crend()const {
            return reverse_iterator(begin());
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

        iterator insert(iterator pos, const T & a) {
            insert(pos, 1, a);
            return pos;
        }

        iterator insert(iterator pos, size_t b, const T & a) {
            if (pos > elem + n) cout << "Error: you are out of array" << endl;
            for(int i = 0; i < b; i++){
                if (n >= cap) {
                    pos = resize(n * 2,pos);
                }
                n++;
                std::move(pos, pos + n, pos + 1);
                *pos = a;
            }
            return pos;
        }

        iterator insert(iterator pos, std::initializer_list<T> il){
            if(n+il.size() >= cap){
                pos = resize(n + il.size() * 2,pos);
            }
            std::move(pos, pos + n, pos + il.size());
            n += il.size();
            std::move(il.begin(), il.end(), pos);
            return pos;
        }

        void erase(iterator pos){
            if (pos > elem + n)  {
                cout << "Error: you are out of array" << endl;
                return;
            }
            std::move(pos + 1, pos + n, pos);
            n--;
        }

        void erase(iterator first, iterator last){
            if ((first > elem + n)||(last > elem + n)) {
                cout << "Error: you are out of array" << endl;
                return;
            }
            std::move(last + 1, last + n, first);
            n--;
            while(first!=last){
                n--;
                first++;
            }
        }

        void swap(vector<T> & v){
            vector<T> a;
            a.elem = new T[v.n];
            a.n = v.n;
            a.n = v.cap;
            std::move(v.begin(), v.end(), a.begin());
            v.elem = new T[n];
            v.n = n;
            v.cap = cap;
            std::move(&elem[0], &elem[n], v.begin());
            elem = new T[a.n];
            n = a.n;
            cap = a.cap;
            std::move(a.begin(), a.end(), elem);
        }

        void clear() {
            n = 0;
            delete[] elem;
            elem = new T[cap];
        }

        iterator emplace(iterator it, const T & args) {
            return insert(it, std::move(args));
        }

        void emplace_back(const T &args) {
            return push_back(std::move(args));
        }
        void emplace_front(const T &args) {
            return push_front(std::move(args));
        }

        friend bool operator== <T> (const vector <T>& left, const vector <T>& right);
        friend bool operator!= <T> (const vector <T>& left, const vector <T>& right);
        friend bool operator< <T> (const vector <T>& left, const vector <T>& right);
        friend bool operator> <T> (const vector <T>& left, const vector <T>& right);
        friend bool operator<= <T> (const vector <T>& left, const vector <T>& right);
        friend bool operator>= <T> (const vector <T>& left, const vector <T>& right);

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

    template < typename T >
    bool operator< (const vector <T>& left, const vector <T>& right) {

        if(left.empty() && right.empty()) return false;
        else if (left.empty()) return true;
        else if (right.empty()) return false;
        else {
            int i = 0;
            while(left[i]==right[i]){
                if((i+1 > left.n)||(i+1 > right.n)) break;
                i++;
            }
            if(left[i] < right[i]) return true;
            else if(left[i] == right[i]){
                if(left.n < right.n) return true;
                else return false;
            }
            else return false;
        }
    }

    template < typename T >
    bool operator> (const vector <T>& left, const vector <T>& right) {
        return !(left < right);
    }

    template < typename T >
    bool operator<= (const vector <T>& left, const vector <T>& right) {

        if(left.empty() && right.empty()) return true;
        else if (left.empty()) return true;
        else if (right.empty()) return false;
        else {
            int i = 0;
            while(left[i]==right[i]){
                if((i+1 > left.n)||(i+1 > right.n)) break;
                i++;
            }
            if(left[i] < right[i]) return true;
            else if(left[i] == right[i]){
                if(left.n < right.n) return true;
                else return true;
            }
            else return false;
        }
    }

    template < typename T >
    bool operator>= (const vector <T>& left, const vector <T>& right) {
        return !(left <= right);
    }
}


#endif //VECTOR_VECTOR_H