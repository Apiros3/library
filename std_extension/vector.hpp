#ifndef EXTENDED_STD_VECTOR
#define EXTENDED_STD_VECTOR

#include <vector>
#include "general/fixed_integer.hpp"

template <typename T>
std::vector<T> &operator +=(std::vector<T> &a, const std::vector<T> &b) {
    assert(a.size() == b.size());
    for(i8 i = 0; i < a.size(); i++) {
        a[i] += b[i];
    }
    return a;
}
template <typename T>
std::vector<T> &operator -=(std::vector<T> &a, const std::vector<T> &b) {
    assert(a.size() == b.size());
    for(i8 i = 0; i < a.size(); i++) {
        a[i] -= b[i];
    }
    return a;
}

template <typename T>
std::vector<T> operator +(std::vector<T> a, const std::vector<T> &b) {
    return a += b;
}
template <typename T>
std::vector<T> operator -(std::vector<T> a, const std::vector<T> &b) {
    return a -= b;
}



#endif