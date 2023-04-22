#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vv = vector<vector<T>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      36と実質同じ、というかこっちの方がシンプル。
      dp[i][k]=i種類以下のコインを使って、k円となる際の、コインの最小枚数 -> dp[m-1][n]が答え
      状態遷移すなわち漸化式を考えると、
      for k in (1...n)
      dp[i][k]=min(dp[i][k - val[i]] + 1, dp[i-1][k])
    */
    int n, m;
    cin >> n >> m;
    vec<int> c(m);
    rep(i, m) cin >> c[i];

    vec<vec<int>> dp(m, vec<int>(n + 1, 0));
    rep(k, n + 1) if (k >= c[0]) dp[0][k] = dp[0][k - c[0]] + 1;
    repg(i, 1, m) {
        rep(k, n + 1) {
            if (k >= c[i])
                dp[i][k] = min({dp[i - 1][k - c[i]] + 1, dp[i - 1][k], dp[i][k - c[i]] + 1});
            else
                dp[i][k] = dp[i - 1][k];
        }
    }
    cout << dp[m - 1][n] << endl;
}
