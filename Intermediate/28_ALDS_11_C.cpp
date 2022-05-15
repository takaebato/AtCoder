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

int main() {
    /*
      BFSの超基本問題。
      正しく実装して距離を求めるもの。有向グラフ。
    */
    int N;
    cin >> N;
    vv<int> g(N);
    rep(i, N) {
        int u, k;
        cin >> u >> k;
        rep(l, k) {
            int v;
            cin >> v;
            g[u - 1].push_back(v - 1);
        }
    }

    ve<int> dist(N, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int nv : g[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    rep(i, N) cout << i + 1 << ' ' << dist[i] << endl;
}
