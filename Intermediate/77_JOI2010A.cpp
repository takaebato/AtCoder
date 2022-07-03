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
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

/*
  愚直に移動をシミュレートすると、m日間で移動距離の計算で線形nかかるので、O(mn)
  だが、距は区間和なので累積和で持っておけば、計算はO(1)で済むので、合計でO(m)になる。
*/
int main() {
    int n, m;
    cin >> n >> m;
    vec<int> t(n), a(m);
    rep(i, n - 1) cin >> t[i];
    rep(i, m) cin >> a[i];
    vec<ll> cum(n + 1, 0);
    rep(i, n) cum[i + 1] = cum[i] + t[i];
    ll dist = 0;
    int cur = 0;
    rep(i, m) {
        dist = (dist + abs(cum[cur + a[i]] - cum[cur])) % 100000;
        cur += a[i];
    }
    cout << dist << endl;
}
