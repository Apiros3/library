#ifndef MST 
#define MST

#include "general/fixed_integer.hpp"
#include <vector>
#include <queue>
#include <tuple>

template<
    class T = i64,
    class Container = std::vector<std::pair<T,i64>>,
    class Compare = std::less<typename Container::value_type>
> class mst {
private:
    T sum = 0;
    std::vector<i64> used;
    // std::vector<std::pair<T,T>> edge_list;
public:
    mst(std::vector<std::vector<std::pair<i64,T>>> adj) : used(adj.size()) /**, edge_list(adj.size())*/ {
        i64 N = adj.size();
        used[0] = 1;
        std::priority_queue<std::pair<T,i64>,Container,Compare> que;
        for(auto u : adj[0]) {
            que.emplace(u.second,u.first);
        }
        while(!que.empty()) {
            auto tmp = que.top(); que.pop();
            if (used[tmp.second]) continue;
            sum += tmp.first;
            i64 cur = tmp.second;
            used[cur] = 1;
            for(auto u : adj[cur]) {
                que.emplace(u.second,u.first);
            }
        }
    }
    T weight() {
        return sum;
    }
};

#endif