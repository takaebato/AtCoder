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
    int N;
    cin >> N;
    vec<string> a(N);
    rep(i, N) cin >> a[i];
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    ll ans = 0;
    rep(i, N) {
        rep(j, N) {
            rep(k, 8) {
                ll sum = 0;
                int ny = i;
                int nx = j;
                rep(l, N) {
                    sum += (a[ny][nx] - '0') * pow(10, N - l - 1);
                    ny += dy[k], nx += dx[k];
                    if (ny < 0) ny = N - 1;
                    if (ny > N - 1) ny = 0;
                    if (nx < 0) nx = N - 1;
                    if (nx > N - 1) nx = 0;
                }
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << endl;
}
