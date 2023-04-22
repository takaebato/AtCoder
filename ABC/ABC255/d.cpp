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
  図を書いて考えたら解けた。
  累積和は当たり前だけど積分と考えられるなと。

  実装の話として、累積和は0を番兵としておいて、要素数N+1で、sum[i+1]=sum[i]+a[i] とするで固定するといいかもしれない。
  あとindexの細かいところは、図を書いて考えるしかない気はする。
*/
int main() {
    int N, Q;
    cin >> N >> Q;
    vec<int> a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());

    vec<ll> sum(N + 1, 0);
    rep1(i, N) sum[i] = sum[i - 1] + a[i - 1];

    rep(qi, Q) {
        ll x;
        cin >> x;
        int id1 = lower_bound(a.begin(), a.end(), x) - a.begin();
        int id2 = upper_bound(a.begin(), a.end(), x) - a.begin();

        ll ans = 0;
        ans = (x * id1 - sum[id1]) + (sum[a.size()] - sum[id2] - x * (a.size() - id2));
        cout << ans << endl;
    }
}
