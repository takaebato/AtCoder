#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
template <class T>
using P = pair<T, T>;
#define push_back = pb;
#define emplace_back = eb;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      0..=N, Di, M日以内、Ck
      N,M,C,D<=1000. 2重ループはいける。
      部分問題、iステップ目・k日目の疲労度の合計値の最小値がわかれば、次のステップも計算できる。
      実装として、最小値を求めるから、番兵は無限大を入れておく。dp[1..=N][0]。本当はdp[0][1..=M]を無限大で埋めたい(0スタートで考えたかったからしてない)
      その場合だと、特別な初期化はdp[1][1]=0で済む。
    */
    int N, M;
    cin >> N >> M;
    vec<int> D(N);
    rep(i, N) cin >> D[i];
    vec<int> C(M + 1);
    rep(i, M) cin >> C[i + 1];
    vvec<int> dp(N + 1, vec<int>(M + 1, 2e9));
    rep(i, M + 1) dp[0][i] = 0;
    repg(i, 1, N + 1) {
        repg(k, 1, M + 1) { dp[i][k] = min(dp[i - 1][k - 1] + D[i - 1] * C[k], dp[i][k - 1]); }
    }
    cout << dp[N][M] << endl;
}
