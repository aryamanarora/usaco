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

    string a;
    cin >> a;
    int i = 0;
    cout << a[i];
    while (a[i] == '/') i++;
    for (; i < a.length(); i++) {
        if (a[i] == '/' and i != 0) {
            while (a[i] == '/') i++;
            if (i == a.length()) break;
            i--;
        }
        cout << a[i];
    }
    cout << endl;
}