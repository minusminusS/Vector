
#ifndef TESTVECTOR_VECTOR_H
#define TESTVECTOR_VECTOR_H

#include <iostream>

inline size_t findPowOf2(size_t n) {
    if (n == 0)
        return 0;
    size_t result = 1;
    while (result < n) {
        result <<= 1;
    }
    return result;
}

namespace vectors{
    template <class T>
    class vector {
        T* c_array;
        size_t c_size;
        size_t c_pointer;

    public:

        explicit vector(size_t size = 0, T value = T(0)) {
            size_t tmp = findPowOf2(size);
            c_array = new T[tmp];
            c_size = tmp;
            c_pointer = size-1;
            for (size_t i = 0; i < tmp; i++) {
                c_array[i] = value;
            }
        }

        vector (const vector<T> &tmp) {
            c_size = tmp.c_size;
            c_array = new T[c_size];
            c_pointer = tmp.c_pointer;
            for (size_t i = 0; i < c_size; i++) {
                c_array[i] = tmp.c_array[i];
            }
        }

        vector<T> &operator=(const vector<T> &tmp) {
            c_size = tmp.c_size;
            c_array = new T[c_size];
            c_pointer = tmp.c_pointer;
            for (size_t i = 0; i < c_size; i++) {
                c_array[i] = tmp.c_array[i];
            }
            return *this;
        }

        ~vector() {
            delete[] c_array;
        }

        // ----------------------
        // Functions
        // ----------------------

        void resize(size_t size = 0) {
            size_t tmp = findPowOf2(size);
            vector<T> tmpV(*this);
            c_array = new T[tmp];
            c_size = tmp;
            c_pointer = size-1;
            for (size_t i = 0; i < tmpV.c_size; i++) {
                c_array[i] = tmpV.c_array[i];
            }
            for (size_t i = tmpV.c_size; i < tmp; i++) {
                c_array[i] = T(0);
            }
        }

        void resize(const vector<T> &tmp) {
            c_size = tmp.c_size;
            c_pointer = tmp.c_pointer;
            for (size_t i = 0; i < c_size; i++) {
                c_array[i] = tmp.c_array[i];
            }
        }

        void push_back(T value) {
            if (++c_pointer >= c_size) {
                resize(c_pointer+1);
            }
            c_array[c_pointer] = value;
        }

        void pop_back(size_t count = 1) {
            while (count) {
                c_array[c_pointer] = T(0);
                count--;
                if (c_pointer == 0) break;
                c_pointer--;
            }
            // In the future I may add a reduction in the size of array
        }

        // ----------------------
        // Getters / Setters
        // ----------------------

        T &operator[](size_t index) {
            if (index > c_pointer) {
                std::cerr << "index out of bounds" << std::endl;
                return c_array[c_pointer];
            }
            return c_array[index];
        }

        [[nodiscard]] size_t size() const {
            return c_pointer+1;
        }

    };
}


#endif //TESTVECTOR_VECTOR_H