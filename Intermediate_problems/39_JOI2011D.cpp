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
      N<=100, N個の数字
      一旦BFを考えると、探索だけで2^(N-2)とかになるかな。
      途中で現れる数字が、0以上20以下と制限してくれているのはかなりポイントだと思った。
      これがないと、用意しなければならない部分問題の範囲が莫大になり得る。
      dp[i][k]=i個までで答えがkとなる計算式の個数
      漸化式を考えると、
      dp[i][k]=dp[i-1][k+val[i]] + dp[i-1][k-val[i]]
    */
    int N;
    cin >> N;
    vec<int> num(N);
    rep(i, N) cin >> num[i];
    vvec<ll> dp(N, vec<ll>(21, 0));
    dp[0][num[0]] = 1;
    repg(i, 1, N) {
        rep(k, 21) {
            if (k + num[i] <= 20) dp[i][k] += dp[i - 1][k + num[i]];
            if (k - num[i] >= 0) dp[i][k] += dp[i - 1][k - num[i]];
        }
    }
    cout << dp[N - 2][num[N - 1]] << endl;
}
