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
      重みなしグラフの最短経路問題。
    */
    int R, C, sy, sx, gy, gx;
    cin >> R >> C >> sy >> sx >> gy >> gx;
    ve<string> g(R);
    rep(i, R) cin >> g[i];
    sy--, sx--, gy--, gx--;

    vv<int> dist(R, ve<int>(C, -1));
    queue<pair<int, int>> que;
    dist[sy][sx] = 0;
    que.push(make_pair(sy, sx));
    const int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};
    while (!que.empty()) {
        pair<int, int> v = que.front();
        int vy = v.first, vx = v.second;
        que.pop();

        rep(i, 4) {
            int y = vy + dy[i], x = vx + dx[i];
            if (y < 0 || y >= R || x < 0 || x >= C) continue;
            if (g[y][x] == '#') continue;
            if (dist[y][x] != -1) continue;
            dist[y][x] = dist[vy][vx] + 1;
            que.push(make_pair(y, x));
        }
    }
    cout << dist[gy][gx] << endl;
}
