#ifndef EXTENDED_STD_SET
#define EXTENDED_STD_SET

#include <set>

template <typename T>
std::set<T> operator |(const std::set<T> &a, const std::set<T> &b) {
    if (a.size() > b.size()) {
        return a|=b;
    }
    else {
        return b|=a;
    }
}
template <typename T>
std::set<T> operator &(const std::set<T> &a, const std::set<T> &b) {
    if (a.size() > b.size()) {
        return a&=b;
    }
    else {
        return b&=a;
    }
}
template <typename T>
std::set<T> operator -(const std::set<T> &a, const std::set<T> &b) {
    return a-=b;
}

template <typename T>
std::set<T> &operator |=(std::set<T> &a, const std::set<T> &b) {
    for(T &u : b) {
        a.insert(u);
    }
}
template <typename T>
std::set<T> &operator &=(std::set<T> &a, const std::set<T> &b) {
    std::set<T> st;
    for(T u : b) {
        if (a.count(u)) {
            st.insert(u);
        }
    }
    return a = st;
}
template <typename T>
std::set<T> &operator -=(std::set<T> &a, const std::set<T> &b) {
    std::set<T> st;
    for(T u : b) {
        if (!a.count(u)) {
            st.insert(u);
        }
    }
    return a = st;
}

// template <typename T>
// std::set<std::set<T>> powerset(std::set<T> st) {

    
// }

#endif