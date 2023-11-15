#ifndef GENERAL_DFS 
#define GENERAL_DFS

#include "general/fixed_integer.hpp"
#include <vector>
#include <algorithm>

template <typename T = i64> 
struct DFS {
private:
    i64 N;
    std::vector<bool> used;

    void dfs(i32 pos, std::vector<std::vector<T>> &adj, i32 &cnt) {
        used[pos] = true;
        dis[pos] = cnt++;
        for(T &u : adj[pos]) {
            if (!used[u]) {
                dfs(u, adj, cnt);
                prev[u] = pos;
            }       
        }
        fin[pos] = cnt++;
    }

public:
    std::vector<i32> dis, fin, prev;
    DFS(std::vector<std::vector<T>> adj, i32 pos = 0) {
        N = adj.size();
        dis.resize(N), fin.resize(N), used.resize(N), prev.resize(N);

        i32 cnt = 0;
        if (pos != -1) {
            dfs(pos, adj, cnt);
        }
        for(i32 i = 0; i < N; i++) {
            if (!used[i]) {
                dfs(i, adj, cnt);
            }
        }
    }
};

#endif