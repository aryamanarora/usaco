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

const int INF = numeric_limits<int>::max();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("dining.in");
    ofstream cout("dining.out");

    int n, m, k;
    cin >> n >> m >> k;
    vector<vii> g(n);
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w; u--, v--;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    vl dist(n, INF);
    function<void()> dijkstra = [&]() {
        set<pair<ll, int>> q;
        dist[n - 1] = 0;
        q.insert({0, n - 1});
        while (!q.empty()) {
            int u = q.begin()->s;
            q.erase(q.begin());

            for (auto &e : g[u]) {
                int v = e.f, d = e.s;
                if (dist[u] + d < dist[v]) {
                    q.erase({dist[v], v});
                    dist[v] = dist[u] + d;
                    q.insert({dist[v], v});
                }
            }
        }
    };

    dijkstra();

    for (int i = 0; i < n - 1; i++) {
        for (auto j = g[i].begin(); j != g[i].end(); j++) {
            if (j->f == n - 1) {
                g[i].erase(j);
                break;
            }
        }
    }
    
    for (int i = 0, v, w; i < k; i++) {
        cin >> v >> w; v--;
        g[n - 1].pb({v, -w});
    }

    vl olddist = dist;
    fill(dist.begin(), dist.end(), INF);

    dijkstra();

    for (int i = 0; i < n - 1; i++) {
        // cout << dist[i] << " " << olddist[i] << '\n';
        cout << (dist[i] <= olddist[i]) << '\n';
    }
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