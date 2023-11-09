#ifndef DEBUG
#define DEBUG

#include <vector>
#include <iostream>

template <typename T>
void debug_ws(T val) {
    try {
        std::cout << val;
    }
    catch (const std::exception &e) {
        std::cout << "error: debug failed. cout cannot be used on val" << endl; 
    }
}
template <typename T>
void debug(T val) {
    debug_ws(val);
    std::cout << " ";
}

template <typename T>
void debug_ws(std::vector<T> &G) {
    for(T &u : G) {
        debug(u);
    }
}
template <typename T>
void debug(std::vector<T> &G) {
    debug_ws(G);
    std::cout << std::endl;
}

template <typename T, typename W>
void debug(std::pair<T,W> &u) {
    debug_ws(u);
    std::cout << " ";
}
template <typename T, typename W>
void debug_ws(std::pair<T,W> &u) {
    std::cout << "{";
    debug_ws(u.first);
    std::cout << ", ";
    debug_ws(u.second);
    std::cout << "}";
}

template <typename T, typename W>
void debug(std::map<T, W> &mp) {
    debug_ws(mp);
    std::cout << std::endl;
}
template <typename T, typename W>
void debug_ws(std::map<T, W> &mp) {
    for(pair<T,W> &u : mp) {
        debug(u);
    }
}

template <typename T> 
void debug_ws(std::set<T> &st) {
    for(T &u : st) {
        debug(u);
    }
}
template <typename T> 
void debug(std::set<T> &st) {
    debug_ws(st);
    std::cout << std::endl;
}

template <typename T> 
void debug_ws(std::multiset<T> &st) {
    for(T &u : st) {
        debug(u);
    }
}
template <typename T> 
void debug(std::multiset<T> &st) {
    debug_ws(st);
    std::cout << std::endl;
}

;
#endif