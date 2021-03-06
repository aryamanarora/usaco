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

    int n, k;
    cin >> n >> k;
    vector<vi> g(n);
    vi degree(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    queue<int> bfs;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) bfs.push(i);
    }

    vi depth(n);
    vi curdegree = degree;
    vector<bool> vis(n);
    while (!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();
        degree[u] = 0;
        vis[u] = true;
        for (auto &v : g[u]) {
            if (vis[v]) continue;
            depth[v] = depth[u] + 1;
            degree[v]--;
            if (degree[v] == 1) {
                bfs.push(v);
            }
        }
    }

    map<int, vi> depths;
    for (int i = 0; i < n; i++) {
        // cout << i + 1 << ": " << depth[i] << " " << curdegree[i] << endl;
        depths[depth[i]].push_back(i);
        if (depth[i] > k) {
            cout << "NO" << endl;
            return 0;
        }
        else if (depth[i] == k) {
            if (curdegree[i] < 3) {
                cout << "NO" << endl;
                return 0;
            }
        }
        else if (depth[i] > 0 and curdegree[i] < 4) {
            cout << "NO" << endl;
            return 0;
        }
        for (auto &v : g[i]) {
            if (abs(depth[i] - depth[v]) != 1) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i <= k; i++) {
        if (depths[i].size() == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}

/*
USE LONG LONG!!!!

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