#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

typedef set<int> si;
typedef set<ii> sii;
typedef set<ld> sd;
typedef set<ll> sl;

typedef map<int, int> mii;
typedef priority_queue<int> pqi;
typedef queue<int> qi;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, n;
    cin >> X >> n;
    vi a(n); for (auto &x : a) cin >> x;

    multiset<int> l;
    l.insert(X);
    set<ii> r;
    r.insert({X, 0});
    for (auto &x : a) {
        auto it = r.lower_bound({x, x});
        ii c = *it;
        r.erase(it);
        l.erase(l.find(c.f - c.s));

        // left
        r.insert({x, c.s});
        l.insert({x - c.s});

        // right
        r.insert({c.f, x});
        l.insert({c.f - x});
        
        // for (auto &x : r) cout << x.s << "->" << x.f << " ";
        // cout << endl;
        // for (auto &x : l) cout << x << " ";
        // cout << endl;
        cout << *(prev(l.end())) << " ";
    }
    cout << endl;
}

/*
USE LONG LONG!!!!

205
100->5

:pray: :fishy15:
:pray: :summitosity:
:pray: :prodakcin:

          .=     ,        =.
  _  _   /'/    )\,/,/(_   \ \
   `//-.|  (  ,\\)\//\)\/_  ) |
   //___\   `\\\/\\/\/\\///'  /
,-"~`-._ `"--'_   `"""`  _ \`'"~-,_
\       `-.  '_`.      .'_` \ ,-"~`/
 `.__.-'`/   (-\        /-) |-.__,'
   ||   |     \O)  /^\ (O/  | .        <-  BESSIE THE COW
   `\\  |         /   `\    /
     \\  \       /      `\ /
      `\\ `-.  /' .---.--.\
        `\\/`~(, '()      ('
         /(O) \\   _,.-.,_)    
        //  \\ `\'`      /
       / |  ||   `""""~"`
     /'  |__||
           `o
*/