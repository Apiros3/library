#ifndef UNIONFIND
#define UNIONFIND

#include <vector>
#include "general/fixed_integer.hpp"

struct UnionFind {
private:
    std::vector<i32> par;
    std::vector<std::vector<i32>> group_elems;
public:
    std::vector<i32> group_size;
    UnionFind(i32 N) : par(N), group_elems(N), group_size(N,1) {
        for(i32 i = 0; i < N; i++) {
            par[i] = i;
            group_elems[i].push_back(i);
        }
    }
    i32 find(i32 N) {
        if (par[N] == N) {
            return N;
        }
        return (par[N] = find(par[N]));
    } 
    bool connected(i32 A, i32 B) {
        return (find(A) == find(B));
    }
    void merge(i32 A, i32 B) {
        A = find(A); B = find(B);
        if (A != B) {
            if (group_size[A] < group_size[B]) {
                std::swap(A,B);
            }
            par[B] = A;
            i32 temp = group_size[A];
            group_size[A] += group_size[B];
            group_elems[A].resize(group_size[A]);
            for(i32 i = 0; i < group_size[B]; i++) {
                group_elems[A][temp+i] = group_elems[B][i];
            }
        }
    }
    std::vector<i32> group(i32 N) {
        return group_elems[N];
    }
};

#endif