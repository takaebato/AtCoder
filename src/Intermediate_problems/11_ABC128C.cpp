#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    // N,M,ki,sij<=10
    // 全通りはスイッチのon,offの組み合わせで2^10通り. 判定で、M個それぞれでkiを線形で辿って10^2. よって、2^10*10^2=10^5程度で行ける.
    int N, M;
    cin >> N >> M;
    vector<vector<int>> t(M);
    rep(i, M) {
        int k;
        cin >> k;
        t[i].resize(k);
        rep(l, k) cin >> t[i][l];
    }
    vector<int> p(M);
    rep(i, M) cin >> p[i];

    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        bool ok = true;
        rep(k, M) {
            int num = 0;
            rep(l, t[k].size()) if (i & (1 << (t[k][l] - 1))) num++;
            if (num % 2 != p[k]) ok = false;
        }
        if (ok) ans++;
    }
    cout << ans << endl;
}
