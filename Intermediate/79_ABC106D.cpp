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
  2変数だから二次元座標で考えると良かった。
  二次元累積和で上手く解ける。
*/
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vvec<int> a(N, vec<int>(N, 0));
    rep(i, M) {
        int l, r;
        cin >> l >> r, l--, r--;
        a[l][r] += 1;
    }
    vvec<int> cum(N + 1, vec<int>(N + 1, 0));
    rep(l, N) rep(r, N) cum[l + 1][r + 1] = cum[l + 1][r] + cum[l][r + 1] - cum[l][r] + a[l][r];
    rep(qi, Q) {
        int p, q;
        cin >> p >> q, p--, q--;
        cout << cum[q + 1][q + 1] - cum[q + 1][p] - cum[p][q + 1] + cum[p][p] << endl;
    }
}

// ボツ。反例あった。
// int main() {
//     int N, M, Q;
//     cin >> N >> M >> Q;
//     vec<P<int, int>> a(M);
//     rep(i, M) cin >> a[i].first >> a[i].second, a[i].first--, a[i].second--;
//     vec<P<int, int>> cum(N + 1);
//     rep(i, N) {
//         rep(j, M) {
//             if (a[j].second <= i) cum[i + 1].first++;
//             if (a[j].first <= i && a[j].second > i) cum[i + 1].second++;
//         }
//     }
//     rep(qi, Q) {
//         int p, q;
//         cin >> p >> q, p--, q--;
//         cout << cum[q + 1].first - cum[p].first - cum[p].second << endl;
//     }
// }
