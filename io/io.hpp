#ifndef IO 
#define IO

#include "general/fixed_integer.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <set>

struct input_parser {
    template <typename T>
    operator T() {
        T x; std::cin >> x;
        return x;
    }
}in;

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, std::pair<T, U> p) {
  return out << p.first << ", " << p.second;
}
template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> vec) {
    for(T& u : vec) {
        out << u << " ";
    }
    return out;
}
template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<std::vector<T>> vec) {
    for(auto &u : vec) out << u << std::endl;
    return out;
}
template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, std::map<T,U> mp) {
    for(std::pair<T,U>& u : mp) out << u << " ";
    return out;
}
template <typename T>
std::ostream& operator<<(std::ostream& out, std::set<T> st) {
    for(T& u : st) out << u << " ";
    return out;
}
template <typename T>
std::ostream& operator<<(std::ostream& out, std::multiset<T> mst) {
    for(T& u : mst) out << u << " ";
    return out;
}

template <typename T, typename U>
std::istream& operator>>(std::istream& in, std::pair<T,U>& p) {
    return in >> p.first >> p.second;
}
template <typename T> 
std::istream& operator>>(std::istream& in, std::vector<T>& vec) {
    for(auto &u : vec) in >> u;
    return in; 
}

#endif