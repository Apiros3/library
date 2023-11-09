#ifndef FACTORIZE_S 
#define FACTORIZE_S

#include <vector>
#include "bit/ctz.hpp"
#include "numerical/pollard_rho.hpp"

//pollard rho factorization
template<typename T>
std::vector<std::pair<T,i32>> factorize_s(T num) {
    std::vector<std::pair<T,i32>> ret;
    i32 tmp = ctz(num);
    if (tmp != 0) {
        ret.emplace_back(2,tmp);
    }
    num >>= tmp;
    while(Miller::isPrime(num) == 0 && num != 1) {
        T min_fact = find_prime_factor(num);
        i32 cnt = 0;
        while(num%min_fact == 0) {
            num /= min_fact;
            cnt++;
        }
        ret.emplace_back(min_fact,cnt);
    }
    if (num != 1) {
        ret.emplace_back(num,1);
    }
    sort(ret.begin(),ret.end());

    return ret;
}


#endif