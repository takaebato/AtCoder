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

/*
  yn = yn - 1 + C[kn], y0=128, 0<=yn<=255
  dp[i][j]=iステップ目で信号値がjの時の二乗和の最小値
  と置くと、i<=10^4, j<=256 で、各ステップでM<=16回だから、O(10^7-8)程度で計算可能。

  少し特殊なのは、初期値が128と決まっているところと、[0, 256)の範囲から外れたら0,255として計算するところか。
  0ステップ目を番兵として用意して、dp[1-N]が本体のステップとして実装した。
*/
int main() {
    int N, M;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) return 0;

        vec<int> c(M), x(N);
        rep(i, M) cin >> c[i];
        rep(i, N) cin >> x[i];
        vvec<int> dp(N + 1, vec<int>(256, 1e8));
        dp[0][128] = 0;

        rep(i, N) {
            rep(j, 256) {
                rep(k, M) {
                    int sum = j + c[k];
                    if (sum < 0)
                        sum = 0;
                    else if (sum > 255)
                        sum = 255;
                    int diff = (sum - x[i]) * (sum - x[i]);
                    dp[i + 1][sum] = min(dp[i + 1][sum], dp[i][j] + diff);
                }
            }
        }
        int ans = INT_MAX;
        rep(i, 256) ans = min(ans, dp[N][i]);
        cout << ans << endl;
    }
}
