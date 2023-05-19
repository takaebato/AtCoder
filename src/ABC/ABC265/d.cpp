#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
template <class T, class U>
using P = pair<T, U>;
#define pb push_back
#define eb emplace_back
#define em emplace
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n + 1); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    ll N, P, Q, R;
    cin >> N >> P >> Q >> R;
    vec<ll> a(N);
    rep(i, N) cin >> a[i];
    vec<ll> cum(N + 1, 0);
    rep(i, N) cum[i + 1] = cum[i] + a[i];
    int y = 1;
    int z = 2;
    int w = 3;
    rep(x, N - 2) {
        while (y < N - 2 && cum[y] - cum[x] < P) y++;
        while (z < N - 1 && cum[z] - cum[y] < Q) z++;
        while (w < N && cum[w] - cum[z] < R) w++;
        if (cum[y] - cum[x] == P && cum[z] - cum[y] == Q && cum[w] - cum[z] == R) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
