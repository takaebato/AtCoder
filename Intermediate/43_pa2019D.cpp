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

map<char, int> cn{{'R', 0}, {'B', 1}, {'W', 2}, {'#', 3}};

int main() {
    /*
      5*N (N<=999), RBW#
      dp[i][RBW]=i列目を(R,B,W)で塗った時の、塗った個数の最小値
    */
    int N;
    cin >> N;
    vec<string> s(5);
    rep(i, 5) cin >> s[i];
    vvec<int> dp(N + 1, vec<int>(3, 1e4));
    repg(i, 1, N + 1) {
        rep(k, 3) {
            int num = 0;
            rep(l, 5) {
                if (cn[s[l][i - 1]] != k) num++;
            }
            dp[i][k] = min(dp[i - 1][(k + 1) % 3], dp[i - 1][(k + 2) % 3]) + num;
            if (i == 1) dp[i][k] = num;
        }
    }
    int ans = INT_MAX;
    rep(i, 3) ans = min(ans, dp[N][i]);
    cout << ans << endl;
}
