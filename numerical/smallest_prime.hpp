#ifndef SMALLEST_PRIME_FACTOR 
#define SMALLEST_PRIME_FACTOR

#include "general/fixed_integer.hpp"
#include <vector>

struct SPF {
private:
public: 
    std::vector<i64> vec;
    SPF(i64 N) : vec(N+1,-1) {
        for(i64 i = 2; i <= N; i++) {
            if (vec[i] != -1) continue;
            for(i64 j = i; j <= N; j += i) {
                if (vec[j] == -1) {
                    vec[j] = i;
                }
            }
        }
    }
    i64 query(i64 N) {
        return vec[N];
    }
};

#endif