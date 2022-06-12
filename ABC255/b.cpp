#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
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
  問題の等価変換が微妙に難しかった。やはり図を書いて考察する時間を取った方がいい。
  各々の明かりを持たない人から明かりを持つ人までの最短距離の、最大値が答え。

  またrootなどは最後に取ったほうが誤差が出にくい。
  あと出力はprintfが少数桁以下の数を指定できていい。
*/
int main() {
    int N, K;
    cin >> N >> K;
    vec<int> a(N, 0);
    rep(i, K) {
        int k;
        cin >> k;
        a[--k] = 1;
    }
    vec<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    auto dist = [=](ll x1, ll x2, ll y1, ll y2) { return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); };

    vector<ll> di(N, LLONG_MAX);
    rep(i, N) {
        if (a[i] == 1) continue;
        rep(j, N) {
            if (a[j] == 0) continue;
            di[i] = min(di[i], dist(x[i], x[j], y[i], y[j]));
        }
    }
    ll ans = 0;
    rep(i, N) if (di[i] != LLONG_MAX) ans = max(ans, di[i]);
    printf("%.12lf\n", sqrt((double)ans));
}
