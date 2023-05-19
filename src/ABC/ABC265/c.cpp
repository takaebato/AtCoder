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

int main() {
    int H, W;
    cin >> H >> W;
    vec<string> g(H);
    vvec<bool> seen(H, vec<bool>(W, false));
    rep(i, H) cin >> g[i];
    int x = 0;
    int y = 0;
    bool ok = true;
    while (1) {
        if (seen[x][y]) {
            ok = false;
            break;
        } else {
            seen[x][y] = true;
        }
        if (g[x][y] == 'U') {
            if (x == 0) break;
            x--;
        } else if (g[x][y] == 'D') {
            if (x == H - 1) break;
            x++;
        } else if (g[x][y] == 'L') {
            if (y == 0) break;
            y--;
        } else if (g[x][y] == 'R') {
            if (y == W - 1) break;
            y++;
        }
    }
    if (ok) {
        printf("%d %d\n", x + 1, y + 1);
    } else {
        cout << -1 << endl;
    }
}
