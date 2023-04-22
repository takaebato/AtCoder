#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
template <class T>
using P = pair<T, T>;
#define pb push_back
#define eb emplace_back
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)
using Graph = vvec<int>;

int main() {
    /*
      dist配列をクエリのループ中にいれていた場合はTLEだった。
      10^5の配列を10^5回初期化すると速度が5倍程度差が出たためこれは注意したほうがいい。

      問題としては、次数の最大値が3かつ、ki<=3という制限のおかげで、毎クエリでBFSして十分間に合った。
    */
    int N, M;
    cin >> N >> M;

    Graph G(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    int Q;
    cin >> Q;
    vec<int> dist(N + 1, -1);
    rep(qi, Q) {
        int x, kx;
        cin >> x >> kx;

        dist[x] = 0;
        queue<int> que;
        que.push(x);
        vec<int> ns;
        ns.pb(x);

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            if (dist[v] == kx) continue;

            for (int nv : G[v]) {
                if (dist[nv] != -1) continue;

                dist[nv] = dist[v] + 1;
                que.push(nv);
                ns.push_back(nv);
            }
        }

        int ans = 0;
        rep(i, ns.size()) {
            ans += ns[i];
            dist[ns[i]] = -1;
        }
        cout << ans << endl;
    }
}
