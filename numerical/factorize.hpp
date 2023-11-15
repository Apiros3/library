#ifndef FACTORIZE 
#define FACTORIZE

#include <vector>
#include "bit/ctz.hpp"

template<typename T>
std::vector<std::pair<T,i32>> factorize(T num) {
    std::vector<std::pair<T,i32>> ret;
    i32 tmp = ctz(num);
    if (!tmp) {
        ret.emplace_back(2,tmp);
    }
    for(T d = 3; d*d <= num; d += 2) {
        if (num%d == 0) {
            int cnt = 0;
            while(num % d == 0) {
                num /= d;
                cnt++;
            }
            ret.emplace_back(d, cnt);
        }
    }
    if (num != 1) {
        ret.emplace_back(num, 1);
    }
    return ret;
}


#endif