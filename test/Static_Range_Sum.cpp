#pragma once
#include "structure/range_sum.hpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, Q; cin >> N >> Q;
    vector<ll> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];

    range_sum RQ(vec);

    while(Q--) {
        ll L, R; cin >> L >> R;
        cout << RQ.range(L,R) << endl;
    }
    
    return 0;
}