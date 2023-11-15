#ifndef TOPOLOGICAL 
#define TOPOLOGICAL

#include "graph/dfs.hpp"

template <typename T>
std::vector<T> topological(std::vector<T> &fin) {
    std::vector<std::pair<T,i32>> lis(N);
    for(i32 i = 0; i < fin.size(); i++) {
        lis.emplace_back(fin[i],i);
    }
    sort(lis.begin(),lis.end(),
        [&](const std::pair<T,i32> &a, const std::pair<T,i32> &b){return a.second < b.second;}
    )
    std::vector<T> ret(N);
    for(i32 i = 0; i < lis.size(); i++) {
        ret[i] = lis[i].first;
    } 
} 

template <typename T>
std::vector<T> topological(std::vector<std::vector<T>> &adj) {
    DFS DF(adj);
    std::vector<T> fin = DF.fin;
    return topological(fin);
}

#endif