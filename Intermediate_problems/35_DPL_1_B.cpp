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
      ナップザック問題。
      まずは探索問題として考察したい。
      BF: 選び方は2^N通り。判定で線形Nかかるから、合計でO(N2^N).
      これでは到底間に合わない -> 状態遷移の圧縮を考える。
      愚直に行くと、各ナップザックを選ぶ、選ばないで2倍で状態数が増えていく。
      しかし、今回欲しいのは価値の最大値だから、各ステップにおいて、何かしらの最大値だけ残せばいいなという発想にはなる。
      例えば、重さの総和<=Wの価値の最大値を毎回残すことを考えると、毎回1つしか残さないことになるが、これは削りすぎ。
      関心があるのは重さの総和だから、重さの総和ごとならmaxだけ残すという圧縮ができる。
      基本は上記だけでいいが、一応重さの総和の最大値がWだから、W以下だけ考えてもう少し削減はできるが、これは本質的ではないのでどっちでもいい気はする。
    */
    int N, W;
    cin >> N >> W;
    ve<int> val(N);
    ve<int> wei(N);
    rep(i, N) cin >> val[i] >> wei[i];
    ve<ve<int>> dp(N, ve<int>(W + 1, 0));

    dp[0][wei[0]] = val[0];
    repg(i, 1, N) {
        rep(k, W + 1) {
            if (k - wei[i] >= 0)
                dp[i][k] = max(dp[i - 1][k - wei[i]] + val[i], dp[i - 1][k]);
            else
                dp[i][k] = dp[i - 1][k];
        }
    }
    int ans = 0;
    rep(i, W + 1) ans = max(ans, dp[N - 1][i]);
    cout << ans << endl;
}
