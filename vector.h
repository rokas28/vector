#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <algorithm>
#include <stdexcept>
namespace vec{
    template <typename T >
    class vector {
    private:
        T *elem;
        size_t cap;
        size_t n;
    public:
        typedef T *iterator;
        typedef T &reference;

        vector() : n{ 0 },elem{ new T[1] }, cap{ 1 } {};
        vector(size_t n, T val) : n{ n }, elem{ new T[n] }, cap{ n } { std::fill_n(elem, n, val); }
        vector(size_t n) : n{ n }, elem{ new T[n] }, cap{ n } {};
        vector(std::initializer_list<T> il)
                : n{ static_cast<std::size_t>(il.size()) },
                  cap{ static_cast<std::size_t>(il.size()) },
                  elem{ new T[il.size()] } {
            std::copy(il.begin(), il.end(), elem);
        }
        ~vector() { delete[] elem; };
        int size() const { return n; }
       void resize(int sz) {
            if (sz <= cap) return;
            T* new_arr = new T[sz];
            for(int i = 0; i < cap; ++i) {
                new_arr[i] = elem[i];
            }
            cap = sz;
            delete[] elem;
            elem = new_arr;
        }

        reference operator[](int i){
            if (i < 0 || size() <= i) throw std::out_of_range {"Vector::operator[]"};
            return elem[i];
        }

        int capacity() const { return cap; }

        void push_back(double x) {
            if (n >= cap) resize(2 * cap);
            elem[n] = x;
            ++n;
        }
    };
}


#endif //VECTOR_VECTOR_H