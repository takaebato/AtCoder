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
  数列問題。
  初項を決めれば他が全て決まるため、DPではなさそうとなる。
  初項の決め方が1e9、項数が1e5だからBFは無理。
  注目すべきは、Mが10しかないこと。答えとしてあり得るで絞れそう。
  A1の選び方は1e9あるが、実際に答えとしてあり得るのは、各項がXiのいずれかと等しい時のみ。要は、最大でも10*10^5通りしかない。
  それ以外はどの項もXiのいずれとも等しくないケースだから、答えにはなり得ない。
  A1と他の項との関係性は計算式で求められる。
*/
int main() {
    int N, M;
    cin >> N >> M;
    vec<int> s(N - 1), x(M);
    rep(i, N - 1) cin >> s[i];
    rep(i, M) cin >> x[i];
    vec<ll> b(N, 0);
    rep1(i, N - 1) b[i] = s[i - 1] - b[i - 1];

    map<ll, ll> mp;
    rep(i, N) {
        rep(j, M) {
            ll z = x[j] - b[i];
            if (i % 2 == 0) z *= -1;
            mp[z]++;
        }
    }
    ll ans = 0;
    for (auto p : mp) ans = max(ans, p.second);
    cout << ans << endl;
}
