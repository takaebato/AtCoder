#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
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

const ll INF = 1LL << 60;

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w) : to(to), w(w) {}
};

using Graph = vvec<Edge>;

/*
  普通のダイクストラ法. O(V^2).
*/
// int main() {
//     int V, E, r;
//     cin >> V >> E >> r;
//     r++;
//     Graph G(V + 1);
//     rep(i, E) {
//         int s, t, w;
//         cin >> s >> t >> w;
//         s++, t++;
//         G[s].pb(Edge(t, w));
//     }

//     vec<bool> used(V + 1, false);
//     vec<ll> dist(V + 1, INF);
//     dist[r] = 0;
//     rep(i, V) {
//         ll min_dist = INF;
//         int min_v = -1;
//         rep1(v, V) {
//             if (!used[v] && dist[v] < min_dist) {
//                 min_dist = dist[v];
//                 min_v = v;
//             }
//         }
//         if (min_v == -1) break;
//         for (auto e : G[min_v]) {
//             dist[e.to] = min(dist[e.to], dist[min_v] + e.w);
//         }
//         used[min_v] = true;
//     }

//     rep1(v, V) {
//         if (dist[v] < INF)
//             cout << dist[v] << endl;
//         else
//             cout << "INF" << endl;
//     }
// }

/*
  ヒープを用いた実装. O(ElogV).
  単純グラフのノード数は E = V-1..=V(V-1)/2 であることから、疎グラフであればO(VlogV)程度で効率がいいが、密グラフになると最悪でO(V^2logV)になり、普通の実装より遅くなる。
*/
int main() {
    int V, E, r;
    cin >> V >> E >> r;
    r++;
    Graph G(V + 1);
    rep(i, E) {
        int s, t, w;
        cin >> s >> t >> w;
        s++, t++;
        G[s].pb(Edge(t, w));
    }

    vec<bool> used(V + 1, false);
    vec<ll> dist(V + 1, INF);
    dist[r] = 0;
    priority_queue<P<ll, int>, vec<P<ll, int>>, greater<P<ll, int>>> que;
    que.em(dist[r], r);

    while (!que.empty()) {
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();
        if (d > dist[v]) continue;

        for (auto e : G[v]) {
            if (dist[e.to] > dist[v] + e.w) {
                dist[e.to] = dist[v] + e.w;
                que.em(dist[e.to], e.to);
            }
        }
    }

    rep1(v, V) {
        if (dist[v] < INF)
            cout << dist[v] << endl;
        else
            cout << "INF" << endl;
    }
}
