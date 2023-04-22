#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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

struct UnionFind {
    vec<int> par, siz;

    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    int root(int x) {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(int x, int y) { return root(x) == root(y); }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;

        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
};

/*
  解き方としては、N,M<=50とかなり少ないことから、各辺を取り除いた場合でループを回して連結判定すればいい。
  連結判定は、DFSでもできるが、ここではUnionFindを使う。
*/
int main() {
    int N, M;
    cin >> N >> M;
    vec<P<int, int>> nodes;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        nodes.eb(a, b);
    }
    int ans = 0;
    UnionFind uf(N);
    rep(i, M) {
        uf.par.assign(N, -1);
        uf.siz.assign(N, 1);

        rep(j, M) {
            if (i == j) continue;  // i番目の辺が存在しないこととする処理
            uf.unite(nodes[j].first, nodes[j].second);
        }

        int cnt = 0;
        rep(j, N) if (j == uf.root(j)) cnt++;
        if (cnt > 1) ans++;  // rootとなるノードの数＝連結成分の数
    }
    cout << ans << endl;
}
