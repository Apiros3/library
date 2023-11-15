#ifndef EXTENDED_STD_PAIR
#define EXTENDED_STD_PAIR

#include <utility>

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

#endif