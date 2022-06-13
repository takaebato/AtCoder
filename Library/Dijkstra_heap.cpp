#include <bits/stdc++.h>

#include <atcoder/all>
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

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    Graph G(V + 1);
    rep(i, E) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].pb(Edge(t, w));
    }

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
