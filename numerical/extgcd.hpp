#ifndef EXTGCD 
#define EXTGCD

#include <iostream>
#include <cassert>
#include "general/fixed_integer.hpp"

// returns gcd of a and b
// stores (x,y) s.t. ax + by = gcd(a,b)
template <typename T>
T extGCD(T a, T b, T &x, T &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    /**
     * d = by + (a%b)x
     * division algo: a - (a/b)b = a%b
     * d = by + ax - (a/b)bx 
     * d = ax + b(y - (a/b)x)
     */
    T d = extGCD(b, a%b, y, x);
    y -= (a/b)*x;
    return d;
}

template <typename T, typename W>
T invmod(T inv, W mod) {    
    T X, Y;
    assert(extGCD(inv, (T)mod, X, Y) == 1);
    return X;
}



#endif