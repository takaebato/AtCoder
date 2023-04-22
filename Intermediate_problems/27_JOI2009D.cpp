#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int m, n;
vector<vector<int>> g;
int cnt = 0;
int mc = 0;
void dfs(int y, int x) {
    g[y][x] = 0;
    cnt++;
    if (y - 1 >= 0 && g[y - 1][x]) dfs(y - 1, x);
    if (y + 1 < n && g[y + 1][x]) dfs(y + 1, x);
    if (x - 1 >= 0 && g[y][x - 1]) dfs(y, x - 1);
    if (x + 1 < m && g[y][x + 1]) dfs(y, x + 1);
    g[y][x] = 1;
    mc = max(mc, cnt--);
}
int main() {
    /*
      m,n<=90.
      全通り：スタート地点の選び方がm*n=810、そこからの移動が20万=2*10^5を超えないらしい。のでO(10^8)でいけそうではある。
      行きがけ時のグラフの変更を帰りがけ時に戻せば、各移動におけるグラフの状態も上手く遷移させられる。
    */
    cin >> m >> n;
    g.resize(n, vector<int>(m));
    rep(i, n) rep(k, m) cin >> g[i][k];
    rep(i, n) rep(k, m) if (g[i][k]) dfs(i, k);
    cout << mc << endl;
}
