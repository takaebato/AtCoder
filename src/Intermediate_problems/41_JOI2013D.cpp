#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      D日間、N種類の服（Ai, Bi, Ci）、隣同士の派手さ|Ci - Ci-1|の総和の最大化。
      漸化式：選択肢はNのうち、Ai<=Ti<=Biのもの。
      dp[i in 1..=D][k in 1..=N]=if(Ak<=Tk<=Bk) dp[i][k]=dp[i-1][l]+|Ck-Cl|
    */
    int D, N;
    cin >> D >> N;
    vec<int> t(D + 1);
    rep(i, D) cin >> t[i + 1];
    vec<int> a(N), b(N), c(N);
    rep(i, N) cin >> a[i] >> b[i] >> c[i];
    vvec<int> dp(D + 1, vec<int>(N, -1));
    repg(i, 1, D + 1) {
        rep(k, N) {
            if (t[i] < a[k] || b[k] < t[i]) continue;
            rep(l, N) {
                if (dp[i - 1][l] != -1) {
                    dp[i][k] = max(dp[i][k], dp[i - 1][l] + abs(c[k] - c[l]));
                } else {
                    dp[i][k] = max(dp[i][k], 0);
                }
            }
        }
    }
    int ans = 0;
    rep(i, N) ans = max(ans, dp[D][i]);
    cout << ans << endl;
}
