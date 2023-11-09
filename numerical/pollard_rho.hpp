#ifndef POLLARD_RHO 
#define POLLARD_RHO

#include "general/fixed_integer.hpp"
#include "numerical/gcd.hpp"
#include "numerical/modmul.hpp"
#include "numerical/miller_rabin.hpp"

//tries to find a factor with probabilistic measures

template <typename T>
T find_prime_factor(T num) {
    if (num%2 == 0) {
        return 2;
    }
    T mx = 1ll + pow(num,0.125);

    for(T c = 1; c < num; c++) {
        auto f = [&](T a) {
            return (T)((modmul(a,a,num) + c)%num); 
        };
        T x = 0, y = 0, g = 1;
        while(g == 1) {
            x = f(x);
            y = f(f(y));
            g = gcd(std::abs(x-y), num);
        }
        if (g == num) continue;
        if (Miller::isPrime(g)) {
            return g;
        }
        else if (Miller::isPrime(num/g)) {
            return num/g;
        }
        else {
            return find_prime_factor(g);
        }
    }
    return num;
}


#endif