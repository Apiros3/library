#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define rep(i,start,end) for(ll i=start; i<end; i++)
#define rrep(i,start,end) for(ll i=start; i>=end; i--)

// gcd and lcm, returns in O(1)
    ll gcd(ll gcdl, ll gcdr) {if (gcdr==0) return gcdl; else return gcd(gcdr,gcdl%gcdr);}
    ll lcm(ll lcml, ll lcmr) {return lcml/gcd(lcml,lcmr)*lcmr;}

ll INF = 1LL << 60;
ld PI = 3.141592653589793;

struct Init {
    Init() {
        cout << setprecision(15);
    }
}init;

int main()
{
    double x = 9.5;
    int y = 4, z = -2;
    while(x > y) {
        ++y;
        if (x < y) 
            z = 0;
        printf("%d\n",z);
    }
    return 0;
}
