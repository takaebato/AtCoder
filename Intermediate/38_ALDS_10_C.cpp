#include <bits/stdc++.h>
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
      最長共通部分列
      部分列は2^N通り存在。で、2^N通り2つを比較するとなると果たしてどうなるのやらという感じ。

      https://ja.wikipedia.org/wiki/%E6%9C%80%E9%95%B7%E5%85%B1%E9%80%9A%E9%83%A8%E5%88%86%E5%88%97%E5%95%8F%E9%A1%8C
      部分問題としては↓のdpを持っていればいい。
      dp[i][k]=i列のxとk列のyの最長共通部分列の長さ -> 答えはdp[m][n]
      各部分問題間の関係性（漸化式）を求めるのは結構難しいと思う。まあ部分問題的な思考回路がちゃんとできていれば難しくはなかったのかな、。

      x[i]とy[k]が同じかどうかで条件分岐が必要になる。
      x[i]==y[k]の時:
        dp[i-1][k-1]における最長部分列の最後の要素として、x[i](=y[k])を加えたものが、dp[i][k]における最長部分列として求められるのは、割と自明か。
      x[i]!=y[k]の時:
        最長部分列の最後の文字がx[i]の時:
          dp[i][k]の最長部分列は、yから最後の要素y[k]を取り除いたとしても変わらないため、dp[i][k]=dp[i][k-1] になる。
        最長部分列の最後の文字がx[i]ではない時:
          dp[i][k]の最長部分列は、xから最後の要素x[k]を取り除いたとしても変わらないため、dp[i][k]=dp[i-1][k-] になる。
      やっぱりこの条件分岐と部分問題間の遷移を考えるのはむずくないか？
    */

    int Q;
    cin >> Q;
    rep(q, Q) {
        string x, y;
        cin >> x >> y;
        vvec<int> dp(x.size() + 1, vec<int>(y.size() + 1, 0));
        repg(i, 1, x.size() + 1) {
            repg(k, 1, y.size() + 1) {
                if (x[i - 1] == y[k - 1])
                    dp[i][k] = dp[i - 1][k - 1] + 1;
                else
                    dp[i][k] = max(dp[i - 1][k], dp[i][k - 1]);
            }
        }
        cout << dp[x.size()][y.size()] << endl;
    }
}
