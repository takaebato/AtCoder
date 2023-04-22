#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int w, h;
int seen[50][50];  // 0: 探索済、1: 未探索 とする
void dfs(int x, int y) {
    seen[x][y] = 0;
    for (int i = -1; i <= 1; i++) {
        for (int k = -1; k <= 1; k++) {
            if (0 <= x + i && x + i <= h - 1 && 0 <= y + k && y + k <= w - 1 && seen[x + i][y + k]) dfs(x + i, y + k);
        }
    }
}

int main() {
    /*
      島の数を数える典型的なdfsの問題。
      要はグラフの連結成分数を数えるということ。
      そして斜め移動OKなのに注意.
      ※AOJだったけど、seenをvector使って毎回resizeしてたらREになった。静的配列にしたら通った。恐らくresizeを繰り返すとメモリの再確保が上手くできないのだろう。
    */
    vector<int> ans;
    while (cin >> w >> h && w && h) {
        memset(seen, 0, sizeof(seen));
        rep(i, h) rep(k, w) cin >> seen[i][k];
        int cnt = 0;
        rep(i, h) rep(k, w) if (seen[i][k]) {
            cnt++;
            dfs(i, k);
        }
        ans.push_back(cnt);
    }
    rep(i, ans.size()) cout << ans[i] << endl;
}
