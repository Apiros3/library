#pragma once
#include "numerical/combinatoric.hpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll T, M; cin >> T >> M;
    combinatoric_s CB(M);

    while(T--) {
        ll N, K; cin >> N >> K;
        cout << CB.nCr(N,K) << endl;
    }
    
    return 0;
}