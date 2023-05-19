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
    int N, M;
    cin >> N >> M;
    vec<int> a(N, 0);
    rep(i, N) cin >> a[i];
    vec<ll> cum(N + 1, 0);
    rep(i, N) cum[i + 1] = cum[i] + a[i];

    vec<ll> ma(N, 0);
    rep(i, N) ma[i] = a[i] * (i + 1);
    vec<ll> mcum(N + 1, 0);
    rep(i, N) mcum[i + 1] = mcum[i] + ma[i];

    ll ans = LLONG_MIN;
    rep(i, N - M + 1) {
        ll sum = 0;
        sum = mcum[i + M] - mcum[i];
        sum = sum - i * (cum[i + M] - cum[i]);
        if (sum > ans) ans = sum;
    }
    cout << ans << endl;
}
