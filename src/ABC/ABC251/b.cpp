#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    vector<int> vec(1e8, 0);
    rep(i, N) {
        vec[a[i]] = 1;
        repg(k, i + 1, N) {
            vec[a[i] + a[k]] = 1;
            repg(l, k + 1, N) { vec[a[i] + a[k] + a[l]] = 1; }
        }
    }
    int ans = 0;
    repg(i, 1, W + 1) if (vec[i] == 1) ans++;
    cout << ans << endl;
}
