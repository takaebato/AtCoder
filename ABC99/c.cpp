#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = j; i < (int)(n); i++)
const int INF = 1000000;

// bottom up
int main() {
    int N;
    cin >> N;
    vector<int> a(10, INF), b(10, INF);
    int x = 1;
    int index = 0;
    while (x <= N) {
        x *= 6;
        a[index++] = x;
    }

    int n;
    index = 0;
    while (x <= N) {
        x *= 9;
        b[index++] = x;
    }

    vector<int> dp(N + 1, 0);

    dp[0] = 0;
    repg(i, 1, N + 1) {
        int cmin = dp[i - 1];
        rep(k, 10) {
            if (i < a[k]) break;
            cmin = min(cmin, dp[i - a[k]]);
        }
        rep(k, 10) {
            if (i < b[k]) break;
            cmin = min(cmin, dp[i - b[k]]);
        }
        dp[i] = cmin + 1;
    }
    cout << dp[N] << endl;
}

// Top down
const int MAX_N = 110000;

int memo[MAX_N];  // memo[i] が i についての答え
int rec(int n) {
    if (n == 0) return 0;               // 終端条件
    if (memo[n] != -1) return memo[n];  // すでに探索済みならリターン

    int res = n;  // INF の気持ち

    // 1, 6, 6^2, ..., を試す (n を超えない範囲で)
    for (int pow6 = 1; pow6 <= n; pow6 *= 6) res = min(res, rec(n - pow6) + 1);

    // 1, 9, 9^2, ..., を試す (n を超えない範囲で)
    for (int pow9 = 1; pow9 <= n; pow9 *= 9) res = min(res, rec(n - pow9) + 1);

    // メモしながらリターン
    return memo[n] = res;
}

int main() {
    int N;
    cin >> N;

    // テーブルを -1 で初期化
    for (int i = 0; i < MAX_N; ++i) memo[i] = -1;
    cout << rec(N) << endl;
}
