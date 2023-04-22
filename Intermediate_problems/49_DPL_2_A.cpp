#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
template <class T, class U>
using P = pair<T, U>;
#define pb push_back
#define eb emplace_back
#define em emplace
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n + 1); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

const int INF = 1e5;
int dist[15][15];
int dp[1 << 15][15];
int rec(int S, int v) {
    if (dp[S][v] != -1) return dp[S][v];

    if(S==(1<<v))
}

/*
  巡回セールスマン問題そのもの。https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361#11-bit-dp
*/
int main() {
    int V, E;
    cin >> V >> E;

    memset(dist, INF, sizeof(dist));
    rep(i, E) {
        int i, j;
        cin >> i >> j >> dist[--i][--j];
    }

    memset(dp, -1, sizeof(dp));
    int res = INF;
    rep(v, V) res = min(res, rec(1 << V - 1, v));
    cout << res << endl;
}
