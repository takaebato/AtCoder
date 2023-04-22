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

int main() {
    int N, M;
    cin >> N >> M;
    vec<int> p(M);
    rep(i, M) cin >> p[i], p[i]--;
    vvec<ll> pr(N - 1, vec<ll>(3));
    rep(i, N - 1) cin >> pr[i][0] >> pr[i][1] >> pr[i][2];
    vec<int> im(N + 1, 0);
    rep(i, M - 1) {
        if (p[i] < p[i + 1]) {
            im[p[i]]++;
            im[p[i + 1]]--;
        } else {
            im[p[i]]--;
            im[p[i + 1]]++;
        }
    }
    ll ans = 0;
    rep(i, N - 1) {
        im[i + 1] += im[i];
        ans += min(pr[i][0] * im[i], pr[i][2] + pr[i][1] * im[i]);
    }
    cout << ans << endl;
}
