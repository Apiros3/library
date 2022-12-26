#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define rep(i,start,end) for(ll i=start; i<end; i++)
#define rrep(i,start,end) for(ll i=start; i>=end; i--)
#define all(a) a.begin(),a.end() 

ll INF = 1LL << 60;
ld PI = 3.141592653589793;

struct Init {
    Init() {
        cout << setprecision(15);
    }
}init;


int main()
{
    //give the number of lines
    //reccomend doing this with ./a.out << EOF
    ll N; cin >> N;
    rep(i,0,N) {
        string tmp;
        getline(cin, tmp);
        cout << '\"' << tmp << "\"," << endl;
    }

    return 0;
}     
