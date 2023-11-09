#ifndef STATIC_RANGE_SUM
#define STATIC_RANGE_SUM

#include <vector>
#include "general/fixed_integer.hpp"

template<
    class T = i64
> struct range_sum {
private:
    std::vector<T> csum;

public:
    range_sum(std::vector<T> vec) {
        i32 N = vec.size();
        csum.resize(N+1);
        for(i32 i = 0; i < N; i++) {
            csum[i+1] = csum[i] + vec[i];
        }
    }
    //sum vec[L..R)
    T range(i32 L, i32 R) {
        return csum[R] - csum[L]; 
    }
    //sum vec[0..N]
    T range(i32 N) {
        return csum[N+1];
    }
};

template <typename T>
void debug(range_sum<T> RS) {
    for(auto u : RS.csum) {
        debug(u);
    }
    std::cout << '\n';
}

#endif