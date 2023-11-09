#ifndef BFS 
#define BFS

#include "general/fixed_integer.hpp"
#include <vector>
#include <queue>

struct BFS_UW {
private:
    i64 INF = 1ll << 60;
public:
    std::vector<i64> dist, prev;
    BFS_UW(std::vector<std::vector<i64>> adj, i64 start = 0) : dist(adj.size(),INF) {
        dist[0] = 0;
        std::queue<i64> que;
        que.push(0);
        while(!que.empty()) {
            i64 top = que.front(); que.pop();
            for(auto u : adj[top]) {
                if (dist[u] > dist[top] + 1) {
                    dist[u] = dist[top] + 1;
                    prev[u] = top;
                    que.push(u);
                } 
            }
        }
    }
    i64 query(i64 Q) {
        return dist[Q];
    }
};

#endif