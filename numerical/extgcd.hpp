#ifndef EXTGCD 
#define EXTGCD

#include <iostream>
#include "general/fixed_integer.hpp"

// returns gcd of a and b
// stores (x,y) s.t. ax + by = gcd(a,b)
i64 extGCD(i64 a, i64 b, i64 &x, i64 &y) {
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
    i64 d = extGCD(b, a%b, y, x);
    y -= (a/b)*x;
    return d;
}

#endif