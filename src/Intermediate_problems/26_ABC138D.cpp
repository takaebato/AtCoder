#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

vector<vector<int>> t;
vector<int> c;
void dfs(int v, int p = -1) {
    if (p != -1) c[v] += c[p];
    for (auto nv : t[v]) {
        if (nv == p) continue;
        dfs(nv, v);
    }
}

int main() {
    /*
      部分木の各ノードに値を足す作業は、行きがけ（or 帰りがけ）に足せばいい。
      ただ、各クエリ操作の計算量は各ノードに一回ずつアクセスしてO(N)で、全体でO(QN)=O(10^10)で間に合わないか。
      -> 累積和的な処理をする。毎クエリごとに全ての子ノードへ情報を送る必要はなく、各親が情報を持っておいて、最後に累積和的に子へ送ればいい。
      ※
      無向グラフでは、一般に、辺の入力で隣接リストでそれぞれを始点とした位置に入れる必要があるのに注意。
      そして、木のDFSだと親さえ弾けばいいので、seen配列は不要で、代わりに親のノードを引数で渡すのが楽か。
    */
    int N, Q;
    cin >> N >> Q;
    t.resize(N);
    c.assign(N, 0);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    rep(i, Q) {
        int p, x;
        cin >> p >> x;
        c[p - 1] += x;
    }
    dfs(0);
    rep(i, N) {
        if (i != 0) cout << ' ';
        cout << c[i];
    }
    cout << endl;
}
