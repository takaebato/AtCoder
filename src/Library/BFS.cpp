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
    int main() {
        int N, M;
        cin >> N >> M;

        Graph G(N + 1);
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            G[a].pb(b);
            G[b].pb(a);
        }

        vec<int> dist(N + 1, -1);
        queue<int> que;
        dist[0] = 0;
        que.push(0);

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (int nv : G[v]) {
                if (dist[nv] != -1) continue;

                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }

        for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
    }
}
