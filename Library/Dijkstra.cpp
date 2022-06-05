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

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    Graph G(V + 1);
    rep(i, E) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].pb(Edge(t, w));
    }

    vec<bool> used(V + 1, false);
    vec<ll> dist(V + 1, INF);
    dist[r] = 0;
    rep(i, V) {
        ll min_dist = INF;
        int min_v = -1;
        rep1(v, V) {
            if (!used[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_v = v;
            }
        }
        if (min_v == -1) break;
        for (auto e : G[min_v]) {
            dist[e.to] = min(dist[e.to], dist[min_v] + e.w);
        }
        used[min_v] = true;
    }

    rep1(v, V) {
        if (dist[v] < INF)
            cout << dist[v] << endl;
        else
            cout << "INF" << endl;
    }
}
