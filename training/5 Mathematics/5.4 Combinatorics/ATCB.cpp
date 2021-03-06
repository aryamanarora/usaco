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

const ll MOD = 1e9 + 7;

ll addmod(ll a, ll b) {
    return (a % MOD + b % MOD) % MOD;
}
ll mulmod(ll a, ll b) {
    ll res = 0;
    a %= MOD;
    b %= MOD;
    if (b > a) swap(a, b);
    while (b > 0) {
        if (b % 2) res = (res + a) % MOD;
        a = (a * 2) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
  	int n;
    cin >> n;
    vi a;
    for (int i = 0, j; i < n; i++) {
        cin >> j;
        if (i == 0) a.push_back(j);
        else if (j != a.back()) a.push_back(j);
    }

    n = a.size();
    vl dp(n);
    map<int, ll> ct;
    ct[a[0]]++;
    for (int i = 1; i < n; i++) {
        dp[i] = addmod(dp[i], dp[i - 1]);
        dp[i] = addmod(dp[i], ct[a[i]]);
        ct[a[i]] = addmod(ct[a[i]], dp[i - 1] + 1);
    }

    cout << addmod(dp[n - 1], 1) << endl;
}

/*
1 3 1 2 3 2 4
1   1
  3     3
      2   2

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