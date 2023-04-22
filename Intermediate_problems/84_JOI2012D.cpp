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

int main() {
    int N, M;
    cin >> N >> M;
    vvec<int> im(N + 20, vec<int>(N + 20, 0));
    int a, b, x;
    rep(i, M) {
        cin >> a >> b >> x;
        im[a][b]++;
        im[a][b + 1]--;
        im[a + x + 1][b]--;
        im[a + x + 1][b + x + 2]++;
        im[a + x + 2][b + 1]++;
        im[a + x + 2][b + x + 2]--;
    }

    rep1(a, N + 5) rep1(b, a + 5) im[a][b] += im[a - 1][b - 1];
    rep1(a, N + 5) rep1(b, a + 5) im[a][b] += im[a - 1][b];
    rep1(a, N + 5) rep1(b, a + 5) im[a][b] += im[a][b - 1];

    int ans = 0;
    rep1(a, N) rep1(b, a) if (im[a][b]) ans++;
    cout << ans << endl;
}
