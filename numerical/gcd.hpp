#ifndef GCD 
#define GCD

#include "general/fixed_integer.hpp"

template <typename T>
T gcd(T a, T b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}

template <typename T>
T lcm(T a, T b) {
    return a/gcd(a,b)*b;
}

#endif