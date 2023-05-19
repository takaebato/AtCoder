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
    int N;
    cin >> N;
    vvec<int> txa(1e5 + 5, vec<int>(5, 0));
    rep(i, N) {
        int t, x, a;
        cin >> t >> x >> a;
        txa[t][x] = a;
    }
    vvec<ll> dp(1e5 + 5, vec<ll>(5, 0));
    repg(i, 1, 1e5 + 2) {
        rep(j, 5) {
            ll prev = 0;
            if (j - 1 >= 0) prev = max(prev, dp[i - 1][j - 1]);
            prev = max(prev, dp[i - 1][j]);
            if (j + 1 < 5) prev = max(prev, dp[i - 1][j + 1]);
            dp[i][j] = txa[i][j] + prev;
        }
        if (i <= 3) {
            repg(j, i + 1, 5) { dp[i][j] = 0; }
        }
    }
    ll ans = 0;
    rep(i, 5) ans = max(ans, dp[1e5 + 1][i]);
    cout << ans << endl;
}
