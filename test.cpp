#pragma once
#include <bits/stdc++.h>
using namespace std;

using ll = long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vvvpll = vector<vvpll>;
using vs = vector<string>;

#define rep(i,start,end) for(ll i=start; i<end; i++)
#define rrep(i,start,end) for(ll i=start; i>=end; i--)
#define all(a) a.begin(),a.end() 

ll INF = 1LL << 60;
ll SINF = 1LL << 30;
ld PI = 3.141592653589793;
ll MOD9 = 998244353LL;
ll MOD10 = 1000000007LL;

#include "apiros3_lib.hpp"
#include "graph/dfs.hpp"
#include "std_extension/maxmin.hpp"
#include "io/io.hpp"

int main() {
    ll N; cin >> N;
    vll vec(N,1);
    cin >> vec;

    cout << vec << endl;

    return 0;
}