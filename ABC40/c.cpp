#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

// 貰う式: dpは0で初期化. 各経路を比較
// int main() {
//     int N;
//     cin >> N;
//     vector<int> a(N);
//     rep(i, N) cin >> a[i];
//     vector<int> dp(N, 0);
//     dp[0] = 0;
//     dp[1] = dp[0] + abs(a[1] - a[0]);
//     repg(i, 2, N) {
//         dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]),
//                     dp[i - 2] + abs(a[i] - a[i - 2]));
//     }
//     cout << dp[N - 1] << endl;
// }

// 貰う式2: dpは無限大で初期化. 自分自身と他の経路を比較。
// int main() {
//     int N;
//     cin >> N;
//     vector<int> a(N);
//     rep(i, N) cin >> a[i];
//     vector<int> dp(N, 2 * pow(10, 9));
//     dp[0] = 0;
//     dp[1] = dp[0] + abs(a[1] - a[0]);
//     repg(i, 2, N) {
//         dp[i] = min(dp[i], dp[i - 1] + abs(a[i] - a[i - 1]));
//         dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
//     }
//     cout << dp[N - 1] << endl;
// }

// 配る式
// int main() {
//     int N;
//     cin >> N;
//     vector<int> a(N);
//     rep(i, N) cin >> a[i];
//     vector<int> dp(N + 5, 2 * pow(10, 9));
//     dp[0] = 0;
//     rep(i, N) {
//         dp[i + 1] = min(dp[i + 1], dp[i] + abs(a[i + 1] - a[i]));
//         dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i + 2] - a[i]));
//     }
//     cout << dp[N - 1] << endl;
// }

// メモ化再帰
int rec(int n, vector<int>& memo, vector<int>& a) {
    if (memo[n] != -1) return memo[n];
    if (n == 0) return memo[n] = 0;
    if (n == 1) return memo[n] = abs(a[1] - a[0]);

    int res = INT_MAX;
    res = min(res, rec(n - 1, memo, a) + abs(a[n] - a[n - 1]));
    res = min(res, rec(n - 2, memo, a) + abs(a[n] - a[n - 2]));
    return memo[n] = res;
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    vector<int> memo(N, -1);
    cout << rec(N - 1, memo, a) << endl;
}
