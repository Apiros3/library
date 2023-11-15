#pragma once
#include <bits/stdc++.h>
#include "numerical/factorize_s.hpp"
using namespace std;
using ll = long long;

int main() {
    
    ll Q; cin >> Q;
    while(Q--) {
        ll N; cin >> N;
        auto tmp = factorize_s(N);
        ll sum = 0;
        for(auto [u,v] : tmp) {
            sum += v;
        }
        cout << sum << " ";
        for(auto [u,v] : tmp) {
            for(int i = 0; i < v; i++) cout << u << " ";
        }
        cout << endl;

    }

    return 0;
}