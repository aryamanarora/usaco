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

    ifstream cin("taming.in");
    ofstream cout("taming.out");

    int n;
    cin >> n;
    vi a(n); for (auto &x : a) cin >> x;

    vi cur(n);
    auto check = [&](vi &x) {
        int diff = 0; for (int i = 0; i < n; i++) diff += (a[i] != x[i]);
        return diff;
    };

    iota(cur.begin(), cur.end(), 0);
    cout << check(cur) << endl;
    for (int i = 1; i < n; i++) {
        int mini = n; vi res;
        for (int j = 0; j < n; j++) {
            if (cur[j] == 0) continue;
            vi test = cur;
            for (int k = j; test[k] != 0 and k < n; k++) test[k] = k - j;
            int t = check(test);
            if (t < mini) {
                mini = t;
                res = test;
            }
        }
        cur = res;
        cout << mini << endl;
        // for (auto &x : cur) cout << x << " ";
        // cout << endl;
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