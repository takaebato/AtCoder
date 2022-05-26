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

int memo[50];
int fib(int n) {
    if (memo[n]) return memo[n];
    if (n == 0) return memo[0] = 1;
    if (n == 1) return memo[1] = 1;

    return memo[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    /*
      フィボナッチ数列の計算。DPの基本中の基本。
      これは特に圧縮もしてなくて、単純にノード間遷移がちゃんと実装できるかという話な気がする。
      3通りでとりあえず実装する。
    */
    // メモ化再帰
    // int N;
    // cin >> N;
    // cout << fib(N) << endl;

    // 配る式
    // int N;
    // cin >> N;
    // vector<int> dp(N + 5, 0);
    // dp[0] = 1;
    // dp[1] = 1;
    // rep(i, N) {
    //     dp[i + 1] += dp[i];
    //     dp[i + 2] += dp[i];
    // }
    // cout << dp[N - 1] << endl;

    // 貰う式
    int N;
    cin >> N;
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    repg(i, 2, N + 1) dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[N] << endl;
}
