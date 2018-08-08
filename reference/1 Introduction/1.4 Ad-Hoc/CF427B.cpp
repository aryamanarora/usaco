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
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, c;
    cin >> n >> t >> c;

    int ans = 0, seq = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a <= t) seq++;
        else {
            if (seq >= c) ans += (seq - c) + 1;
            seq = 0;
        }
    }
    cout << ans << endl;
}