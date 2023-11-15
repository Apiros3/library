#ifndef EXTENDED_STD_MAXMIN
#define EXTENDED_STD_MAXMIN

#include <vector>

template <typename T>
T max(std::vector<T> vec) {
    T mx = vec[0];
    for(auto u : vec) {
        mx = std::max(mx, u);
    }
    return mx;
} 

template <typename T>
T min(std::vector<T> vec) {
    T mn = vec[0];
    for(auto u : vec) {
        mn = std::min(mn, u);
    }
    return mn;
} 


#endif