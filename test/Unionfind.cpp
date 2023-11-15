#pragma once
#include "structure/unionfind.hpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, Q; cin >> N >> Q;
    UnionFind UF(N);

    for(int i = 0; i < Q; i++) {
        ll T, U, V; cin >> T >> U >> V;
        if (!T) {
            UF.merge(U,V);
        }
        else {
            cout << UF.connected(U,V) << endl;
        }
    }
    
    return 0;
}