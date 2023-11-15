#ifndef KNAPSACK 
#define KNAPSACK

#include <vector>
#include "general/fixed_integer.hpp"
#include "std_extension/maxmin.hpp"

template <typename T>
struct Knapsack01 {
private:
    T N;
    U W;
    std::vector<bool> used;
    
    void smallN(std::vector<T> value, std::vector<T> weight) {
        
    }
    void smallW(std::vector<T> value, std::vector<T> weight) {

    }
    void smallV(std::vector<T> value, std::vector<T> weight) {
        
    }

public:
    template <typename U, typename V>
    Knapsack01 (T N, U W, std::vector<std::pair<V,V>> VW, i32 maxN = 40) : N(N), W(W) {
        std::vector<V> value(N), weight(N);
        for(i32 T i = 0; i < N; i++) {
            value[i] = VW[i].first;
            weight[i] = VW[i].second;
        }
        if (N <= maxN) {
            smallN(value, weight);
        }
        else if (max(value) < max(weight)) {
            smallV(value, weight);
        }
        else {
            smallW(value, weight);
        }
    }
    template <typename U, typename V>
    Knapsack01 (T N, U W, std::vector<V> value, std::vector<T> weight, i32 maxN = 40) : N(N), W(W) {
        if (N <= maxN) {
            smallN(value, weight);
        }
        else if (max(value) < max(weight)) {
            smallV(value, weight);
        }
        else {
            smallW(value, weight);
        }
    }

};

#endif