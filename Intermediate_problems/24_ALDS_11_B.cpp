#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

template <typename T>
void pr(T v) {
    cout << "---" << endl;
    rep(i, v.size()) {
        if (i != 0) cout << ", ";
        cout << v[i];
    }
    cout << endl;
}

vector<vector<int>> g;
vector<int> d;
vector<int> f;
vector<bool> seen;
int cnt = 0;
void dfs(int v) {
    cnt++;
    seen[v] = true;
    d[v] = cnt;
    for (auto nv : g[v]) {
        if (seen[nv]) continue;
        dfs(nv);
    }
    cnt++;
    f[v] = cnt;
};

int main() {
    /*
      DFSの基本問題。
      隣接リストでグラフが与えられて、行きがけと帰りがけを出力せよという問題。
      （ラムダ式の再帰はC++11だとハック的にしかできないらしい。C++23から標準実装されるらしい。https://yohhoy.hatenadiary.jp/entry/20211025/p1）
    */
    int N;
    cin >> N;
    g.resize(N);
    rep(i, N) {
        int u, k;
        cin >> u >> k;
        rep(l, k) {
            int v;
            cin >> v;
            g[u - 1].push_back(v - 1);
        }
    }

    d.resize(N);
    f.resize(N);
    seen.assign(N, false);
    rep(i, N) if (!seen[i]) dfs(i);
    rep(i, N) cout << i + 1 << ' ' << d[i] << ' ' << f[i] << endl;
}
