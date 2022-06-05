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

const ll INF = 1LL << 60;

int main() {
    /*
      dp[l][i][k]=頂点0..lのみを中継頂点として通って良いとした場合の、頂点iからkへの最短路長
      漸化式：
      0..=lを通っていい場合の最短経路 ＝ min(lを通らない場合の最短経路 or lを通る場合の最短経路)
      dp[l+1][i][k] = min(dp[l][i][k], dp[l][i][l] + dp[l][l][k])
      初期化：
        i==k => 0
        辺(i,k) => w(e)
        それ以外 => INF

      実装上、dpは2次元でいける。
    */

    // 頂点番号：0..V
    int V, E;
    cin >> V >> E;
    vvec<ll> dp(V, vec<ll>(V, INF));

    rep(i, E) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        dp[a][b] = w;
    }
    rep(v, V) dp[v][v] = 0;

    rep(l, V) {
        rep(i, V) {
            rep(k, V) { dp[i][k] = min(dp[i][k], dp[i][l] + dp[l][k]); }
        }
    }

    bool neg = false;
    rep(v, V) if (dp[v][v] < 0) neg = true;
    if (neg)
        cout << "NEGATIVE CYCLE" << endl;
    else
        rep(i, V) {
            rep(k, V) {
                if (k) cout << " ";
                if (dp[i][k] < INF / 2)
                    cout << dp[i][k];
                else
                    cout << "INF";
            }
            cout << endl;
        }
}
