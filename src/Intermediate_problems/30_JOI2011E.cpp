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
      これは最短経路問題を最大で9回解くだけか。
      各地点を訪れる順番は決まってるから、計算量はO(HWN)=O(9*10^6)。判定も計算量に含むならもっと多いか。
    */
    int H, W, N;
    cin >> H >> W >> N;
    ve<string> g(H);
    rep(i, H) cin >> g[i];

    int sy, sx;
    ve<pair<int, int>> f(N);
    rep(i, H) rep(k, W) {
        if (g[i][k] == 'S') sy = i, sx = k;
        rep(l, N) if (g[i][k] == '1' + l) f[l] = make_pair(i, k);
    }

    int ans = 0;
    const int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
    rep(i, N) {
        vv<int> dist(H, ve<int>(W, -1));
        queue<pair<int, int>> que;
        if (i != 0) sy = f[i - 1].first, sx = f[i - 1].second;
        dist[sy][sx] = 0;
        que.push(make_pair(sy, sx));

        while (!que.empty()) {
            pair<int, int> v = que.front();
            int vy = v.first, vx = v.second;
            que.pop();
            rep(k, 4) {
                int y = vy + dy[k], x = vx + dx[k];
                if (y < 0 || y >= H || x < 0 || x >= W) continue;
                if (g[y][x] == 'X') continue;
                if (dist[y][x] != -1) continue;
                dist[y][x] = dist[vy][vx] + 1;
                que.push(make_pair(y, x));
            }
        }
        ans += dist[f[i].first][f[i].second];
    }
    cout << ans << endl;
}
