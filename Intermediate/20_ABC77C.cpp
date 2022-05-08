#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      N<=10^5. Ai,Bi,Ci<=10^9.
      BF: 全組み合わせでN^3=10^15で超過. 判定は定数でOK.
      答えとしてあり得る：答えの状態数は組み合わせ数と同じかな.
      一部決定で決まる：
      1. ソートしておけば、探索を3N程度で行けるかもしれない. 判定は計算で求まるから定数.
      2. もしくは、ソートしておいて二分探索. 二つ決まれば三つ目は計算で決められる. 探索がN^2で判定がlogNだが、これは10^10超えるからダメ.
         キャッシュしておけばいけるか. 累積和を持っておく. 10^5ならメモリも持つ.計算量はO(nlogn).
         3段階ある場合は、2段階に分けて、片方の結果を累積和などでキャッシュするのは頻出かもしれない.
         -> 真ん中で探索して一つ目と三つ目で、判定計算しに行く方がメモリ要らなくてスマートだった.
    */
    // 1. 上手いこと線形探索3回分程度で済ます. （llでのキャストが必要なことに注意）
    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];
    rep(i, N) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ans = 0;
    int ia = 0;
    int ic = 0;
    rep(i, N) {
        while (ia < N && a[ia] < b[i]) ia++;
        while (ic < N && c[ic] <= b[i]) ic++;
        ans += (ll)ia * (N - ic);
    }
    cout << ans << endl;

    // 2. 自力解. 二分探索とキャッシュ.
    // int N;
    // cin >> N;
    // vector<int> a(N), b(N), c(N);
    // rep(i, N) cin >> a[i];
    // rep(i, N) cin >> b[i];
    // rep(i, N) cin >> c[i];
    // sort(a.begin(), a.end());
    // sort(b.begin(), b.end());
    // sort(c.begin(), c.end());

    // vector<ll> bc(N);
    // repi(i, N) {
    //     auto itc = upper_bound(c.begin(), c.end(), b[i]);
    //     if (i == N - 1) {
    //         bc[i] = c.end() - itc;
    //     } else {
    //         bc[i] = bc[i + 1] + c.end() - itc;
    //     }
    // }

    // ll ans = 0;
    // rep(i, N) {
    //     auto itb = upper_bound(b.begin(), b.end(), a[i]);
    //     if (itb == b.end()) continue;
    //     ans += bc[itb - b.begin()];
    // }
    // cout << ans << endl;

    // 2-2 真ん中で探索する. メモリ消費しない上に、実装が圧倒的にシンプル. 計算量はO(nlogn)
    // int N;
    // cin >> N;
    // vector<int> a(N), b(N), c(N);
    // rep(i, N) cin >> a[i];
    // rep(i, N) cin >> b[i];
    // rep(i, N) cin >> c[i];
    // sort(a.begin(), a.end());
    // sort(b.begin(), b.end());
    // sort(c.begin(), c.end());

    // ll ans = 0;
    // rep(i, N) {
    //     auto ita = lower_bound(a.begin(), a.end(), b[i]);
    //     auto itc = upper_bound(c.begin(), c.end(), b[i]);
    //     ans += (ita - a.begin()) * (c.end() - itc);
    // }
    // cout << ans << endl;
}
