#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
using ve = vector<T>;
template <class T>
using vv = vector<vector<T>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      ナップザックで、同じ物を何度も選べるパターン。
      BFの全探索だと、N^(W/wmin)の探索が必要。
      ただ価値の総和の最大値だけわかればいいため、maxで圧縮していけそう
      かつ、やはりステップごとにルールベースで枝刈り・圧縮していけるケースになる。
      関心があるのは、価値の総和と、重さの総和。重さの総和ごとに価値の総和をmaxで圧縮していく。

      dp=i種類の荷物を用いて、W以下の重さの総和の場合での、価値の総和の最大値
      漸化式：
      for k in (1...W)
      dp[i][k]=max(dp[i - 1][k - w[i]] + val[i], dp[i - 1][k], dp[i][k - w[i]] + val[i])

      その同ステップのノード同士にもエッジがあるという感じ。
      漸化式として、状態が二つあるのなら、iが前からの遷移だけでなく、iが同じでもkが前からの遷移は存在し得るな、と。
      そして有向グラフだから、fromである重さが軽い方は先に算出されていないといけないな、と。
    */
    int N, W;
    cin >> N >> W;
    ve<int> val(N);
    ve<int> wei(N);
    rep(i, N) cin >> val[i] >> wei[i];
    ve<ve<int>> dp(N, ve<int>(W + 1, 0));

    rep(k, W + 1) if (k - wei[0] >= 0) dp[0][k] = dp[0][k - wei[0]] + val[0];
    repg(i, 1, N) {
        rep(k, W + 1) {
            if (k - wei[i] >= 0)
                dp[i][k] = max(dp[i][k - wei[i]] + val[i], dp[i - 1][k]});
            else
                dp[i][k] = dp[i - 1][k];
        }
    }
    int ans = 0;
    rep(i, W + 1) ans = max(ans, dp[N - 1][i]);
    cout << ans << endl;
}
