#ifndef EXTENDED_STD_VECTOR
#define EXTENDED_STD_VECTOR

#include <vector>
#include "general/fixed_integer.hpp"


template<typename T>
std::vector<T>& operator +=(std::vector<T> &lhs, const std::vector<T> &rhs) {
    if (lhs.size() != rhs.size()) {
        throw std::length_error("vectors must be same size to add");
    }
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] += rhs[i];
    }
    return lhs;
}
template<typename T>
std::vector<T> operator +(std::vector<T> lhs, const std::vector<T> &rhs) {
    return lhs += rhs;
}
template<typename T>
std::vector<T>& operator -=(std::vector<T> &lhs, const std::vector<T> &rhs) {
    if (lhs.size() != rhs.size()) {
        throw std::length_error("vectors must be same size to subtract");
    }
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] -= rhs[i];
    }
    return lhs;
}
template<typename T>
std::vector<T> operator -(std::vector<T> lhs, const std::vector<T> &rhs) {
    return lhs -= rhs;
}
template<typename T>
std::vector<T>& operator *=(std::vector<T> &lhs, const std::vector<T> &rhs) {
    if (lhs.size() != rhs.size()) {
        throw std::length_error("vectors must be same size to multiply");
    }
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] *= rhs[i];
    }
    return lhs;
}
template<typename T>
std::vector<T> operator *(std::vector<T> lhs, const std::vector<T> &rhs) {
    return lhs *= rhs;
}
template<typename T>
std::vector<T>& operator /=(std::vector<T> &lhs, const std::vector<T> &rhs) {
    if (lhs.size() != rhs.size()) {
        throw std::length_error("vectors must be same size to divide");
    }
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] /= rhs[i];
    }
    return lhs;
}
template<typename T>
std::vector<T> operator /(std::vector<T> lhs, const std::vector<T> &rhs) {
    return lhs /= rhs;
}

template<typename T>
std::vector<T>& operator +=(std::vector<T> &lhs, const T& rhs) {
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] += rhs;
    }
    return lhs;
}
template<typename T>
std::vector<T> operator +(std::vector<T> lhs, const T& rhs) {
    return lhs += rhs;
}
template<typename T>
std::vector<T>& operator -=(std::vector<T> &lhs, const T& rhs) {
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] -= rhs;
    }
    return lhs;
}
template<typename T>
std::vector<T> operator -(std::vector<T> lhs, const T& rhs) {
    return lhs -= rhs;
}
template<typename T>
std::vector<T>& operator *=(std::vector<T> &lhs, const T& rhs) {
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] *= rhs;
    }
    return lhs;
}
template<typename T>
std::vector<T> operator *(std::vector<T> lhs, const T& rhs) {
    return lhs *= rhs;
}
template<typename T>
std::vector<T>& operator /=(std::vector<T> &lhs, const T& rhs) {
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] /= rhs;
    }
    return lhs;
}
template<typename T>
std::vector<T> operator /(std::vector<T> lhs, const T& rhs) {
    return lhs /= rhs;
}
template<typename T>
std::vector<T>& operator %=(std::vector<T> &lhs, const T& rhs) {
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] %= rhs;
    }
    return lhs;
}
template<typename T>
std::vector<T> operator %(std::vector<T> lhs, const T& rhs) {
    return lhs %= rhs;
}


#endif