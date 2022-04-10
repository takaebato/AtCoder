#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = j; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<vector<ll>> dp(N + 1, vector<ll>(10));
    int X = 998244353;

    repg(k, 1, 10) dp[1][k] = 1;
    repg(i, 2, N + 1) {
        repg(k, 1, 10) {
            if (k == 1) {
                dp[i][k] = (dp[i - 1][k] + dp[i - 1][k + 1]) % X;
            } else if (k == 9) {
                dp[i][k] = (dp[i - 1][k] + dp[i - 1][k - 1]) % X;
            } else {
                dp[i][k] =
                    (dp[i - 1][k] + dp[i - 1][k - 1] + dp[i - 1][k + 1]) % X;
            }
        }
    }
    int sum = 0;
    repg(k, 1, 10) sum = (sum + dp[N][k]) % X;
    cout << sum << endl;
}
