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
      N<=100
      BFだと、愚直の探索だけで3^Nかかる。
      dp[i][k][l]: i日目まで、kはi日目のパスタの種類、lはi日目時点で連続しているかどうかで、値は予定の通り数
      K日分はパスタの種類が決められているらしいから、そこだけ漸化式の遷移を条件分岐する必要はある。
    */
    int N, K;
    cin >> N >> K;
    vec<int> pre(N, 0);
    rep(i, K) {
        int day;
        cin >> day >> pre[day - 1];
    }
    vvec<vec<int>> dp(N, vvec<int>(4, vec<int>(2, 0)));
    if (pre[0])
        dp[0][pre[0]][0] = 1;
    else
        repg(i, 1, 4) dp[0][i][0] = 1;
    repg(i, 1, N) {
        repg(k, 1, 4) {
            if (pre[i])
                if (pre[i] != k) continue;
            repg(l, 1, 4) {
                if (k == l) {
                    dp[i][k][1] += dp[i - 1][l][0] % 10000;
                } else {
                    dp[i][k][0] += (dp[i - 1][l][0] + dp[i - 1][l][1]) % 10000;
                }
            }
        }
    }
    int ans = 0;
    repg(i, 1, 4) rep(k, 2) ans += dp[N - 1][i][k] % 10000;
    cout << ans % 10000 << endl;
}
