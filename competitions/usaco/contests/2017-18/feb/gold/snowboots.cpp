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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("snowboots.in");
    ofstream cout("snowboots.out");
    
    int n, b;
    cin >> n >> b;
    vi a(n); for (auto &x : a) cin >> x;

    si gaps;
    priority_queue<ii> pq;
    for (int i = 0; i < n; i++) {
        pq.push({a[i], i});
        gaps.insert(i);
    }

    vector<pair<ii, int>> queries(b);
    int ct = 0;
    for (auto &x : queries) {
        cin >> x.f.f >> x.f.s;
        x.s = ct++;
    }
    sort(queries.rbegin(), queries.rend());

    vector<bool> ans(b);
    int maxgap = 1;
    for (auto &x : queries) {
        // cerr << x.f.f << " " << x.f.s << " " << x.s << endl;
        while (pq.top().f > x.f.f and gaps.size() > 2) {
            ii cur = pq.top();
            pq.pop();
            gaps.erase(cur.s);
            auto it = gaps.lower_bound(cur.s);
            auto it2 = it; it2--;
            maxgap = max(maxgap, *it - *it2);
        }
        if (x.f.s >= maxgap) ans[x.s] = 1;
        else ans[x.s] = 0;
    }

    for (auto x : ans) cout << x << '\n';
}

/*
USE LONG LONG!!!!

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