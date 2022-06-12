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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int N, K;
    cin >> N >> K;
    vec<int> a(N), b(N);
    rep(i, N) cin >> a[i];
    b = a;
    sort(a.begin(), a.end());
    vec<multiset<int>> g(K);
    rep(i, N) { g[i % K].insert(a[i]); }
    rep(i, N) {
        auto it = g[i % K].find(b[i]);
        if (it != g[i % K].end()) {
            g[i % K].erase(it);
        } else {
            cout << "No" << endl;
            return 0;
        };
    }
    cout << "Yes" << endl;
}
