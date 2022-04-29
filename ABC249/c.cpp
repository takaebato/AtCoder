#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> s(N);
    rep(i, N) cin >> s[i];
    int res = 0;

    for (int bit = 0; bit < (1 << N); ++bit) {
        vector<int> sum(30, 0);
        int num = 0;
        rep(i, s.size()) {
            if (bit & (1 << i)) {
                rep(k, s[i].size()) sum[s[i][k] - 'a']++;
            }
        }
        rep(i, sum.size()) {
            if (sum[i] == K) num++;
        }
        res = max(num, res);
    }
    cout << res << endl;
}
