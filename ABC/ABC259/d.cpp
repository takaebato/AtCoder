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
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

vvec<int> G;
vector<bool> seen;
void dfs(int v) {
    seen[v] = true;  // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;  // next_v が探索済だったらスルー
        dfs(next_v);                 // 再帰的に探索
    }
}

struct V {
    ll x, y, r;
    V(ll x = 0, ll y = 0, ll r = 0) : x(x), y(y), r(r) {}
};

int main() {
    int N;
    cin >> N;
    V s, t;
    cin >> s.x >> s.y >> t.x >> t.y;
    vec<V> c(N);
    rep(i, N) cin >> c[i].x >> c[i].y >> c[i].r;

    G.resize(N);

    auto pow2 = [](ll x) { return x * x; };
    auto dist = [&](V a, V b) { return pow2(a.x - b.x) + pow2(a.y - b.y); };

    auto isIsc = [&](V a, V b) {
        ll d = dist(a, b);
        if (d > pow2(a.r + b.r)) {
            return false;
        } else if (d < pow2(a.r - b.r)) {
            return false;
        } else {
            return true;
        }
    };

    int si, ti;
    rep(i, N) {
        repg(j, i + 1, N) {
            if (isIsc(c[i], c[j])) {
                G[i].pb(j);
                G[j].pb(i);
            }
        }
        if (pow2(c[i].x - s.x) + pow2(c[i].y - s.y) == pow2(c[i].r)) si = i;
        if (pow2(c[i].x - t.x) + pow2(c[i].y - t.y) == pow2(c[i].r)) ti = i;
    }

    seen.assign(N, false);  // 全頂点を「未訪問」に初期化
    dfs(si);
    if (seen[ti]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
