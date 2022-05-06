#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    // N<=12, M<=N(N-1)/2
    // 選び方は2^N, 判定は、2人の組み合わせが存在するかだから、NC2*M=MN^2=N^4=10^4程度だろうか. 合計で、2^N*N4=10^7-8くらい？
    // 判定のMは二分探索できて、2^N*N^2*logN=10^5程度にはできるか？
    // 多次元でもpairやtupleのsortで二分探索が一発で出来るのはかなり重要.
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> r(M);
    rep(i, M) cin >> r[i].first >> r[i].second;
    sort(r.begin(), r.end());

    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        bool ok = true;
        rep(k, N) {
            repg(l, k + 1, N) {
                if ((i & (1 << k)) && (i & (1 << l))) {
                    bool found = binary_search(r.begin(), r.end(), make_pair(k + 1, l + 1));
                    if (!found) ok = false;
                }
            }
        }
        if (ok) {
            int cnt = 0;
            rep(k, N) if (i & (1 << k)) cnt++;
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}
