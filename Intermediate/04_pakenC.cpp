#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    // N<=100, M<=100, Aij<=10^8. 全通りは曲の選び方でMC2. それぞれの計算でN. だからO(NM^2)で済む.
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(N, vector<int>(M));
    rep(i, N) rep(k, M) cin >> a[i][k];
    ll ans = 0;
    rep(i, M) {
        repg(k, i + 1, M) {
            ll sum = 0;
            rep(l, N) sum += max(a[l][i], a[l][k]);
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}
