#pragma once
#include "numerical/miller_rabin.hpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll Q; cin >> Q;
    while(Q--) {
        ll N; cin >> N;
        cout << (Miller::isPrime(N) ? "Yes" : "No") << endl;
    }
    
    return 0;
}