#ifndef EXTENDED_OPERATOR
#define EXTENDED_OPERATOR

#include <utility>
#include <vector>

template<typename T, typename W>
std::pair<T,W>& operator +=(std::pair<T,W> &lhs, const std::pair<T,W> &rhs) {
    lhs.first += rhs.first;
    lhs.second += rhs.second;
}
template<typename T, typename W>
std::pair<T,W> operator +(std::pair<T,W> lhs, const std::pair<T,W> &rhs) {
    return lhs += rhs;
}
template<typename T, typename W>
std::pair<T,W>& operator -=(std::pair<T,W> &lhs, const std::pair<T,W> &rhs) {
    lhs.first -= rhs.first;
    lhs.second -= rhs.second;
}
template<typename T, typename W>
std::pair<T,W> operator -(std::pair<T,W> lhs, const std::pair<T,W> &rhs) {
    return lhs -= rhs;
}
template<typename T, typename W>
std::pair<T,W>& operator *=(std::pair<T,W> &lhs, const std::pair<T,W> &rhs) {
    lhs.first *= rhs.first;
    lhs.second *= rhs.second;
}
template<typename T, typename W>
std::pair<T,W> operator *(std::pair<T,W> lhs, const std::pair<T,W> &rhs) {
    return lhs *= rhs;
}
template<typename T, typename W>
std::pair<T,W>& operator /=(std::pair<T,W> &lhs, const std::pair<T,W> &rhs) {
    lhs.first /= rhs.first;
    lhs.second /= rhs.second;
}
template<typename T, typename W>
std::pair<T,W> operator /(std::pair<T,W> lhs, const std::pair<T,W> &rhs) {
    return lhs /= rhs;
}

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