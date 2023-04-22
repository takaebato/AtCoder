#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int div = 998244353;
    int N, M, K;
    cin >> N >> M >> K;
    int L = N * M;
    vector<vector<ll>> dp(N + 1, vector<ll>(L + 1, 0));
    repg(i, 1, M + 1) if (M <= K) dp[1][i] = 1;
    repg(i, 2, N + 1) {
        repg(k, 1, L + 1) {
            repg(l, 1, M + 1) {
                if (k + l <= K) {
                    dp[i][k + l] = (dp[i][k + l] + dp[i - 1][k]) % div;
                }
            }
        }
    }
    int ans = 0;
    repg(i, 1, K + 1) ans = (ans + dp[N][i]) % div;
    cout << ans << endl;
}
