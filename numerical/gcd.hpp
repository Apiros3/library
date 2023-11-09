#ifndef GCD 
#define GCD

#include "general/fixed_integer.hpp"

template<typename T>
T gcd(T a, T b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}

#endif