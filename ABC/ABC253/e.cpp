#include <bits/stdc++.h>
#include<atcoder/all>
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

const int MOD = 998244353;

int main() {
    int N, M, K:
    cin >> N >> M >> K;
    vec<vec<ll>> dp(N, vec<ll>(M + 1, 0));
    repg(i, 1, M + 1) dp[0][i] = i;
    repg(i, 1, N) {
        repg(k, 1, M + 1) {
            if (k > 1) dp[i][k] += dp[i][k - 1] % MOD;
            if (k >= K) dp[i][k] += dp[i - 1][k - K] % MOD;
            if ((k + K) <= M) {
                if ((k + K - 1) >= 1) {
                    if (dp[i - 1][M] > dp[i - 1][k + K - 1]) {
                        dp[i][k] += (dp[i - 1][M] - dp[i - 1][k + K - 1]) % MOD;
                    } else {
                        dp[i][k] += (dp[i - 1][M] + MOD - dp[i - 1][k + K - 1]) % MOD;
                    }
                } else {
                    if (dp[i - 1][M] > dp[i - 1][1]) {
                        dp[i][k] += (dp[i - 1][M] - dp[i - 1][1]) % MOD;
                    } else {
                        dp[i][k] += (dp[i - 1][M] + MOD - dp[i - 1][1]) % MOD;
                    }
                }
            }
            dp[i][k] %= MOD;
        }
    }
    cout << dp[N - 1][M] % MOD << endl;
}
