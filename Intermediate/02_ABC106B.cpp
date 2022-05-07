#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    // N<=200. 約数の探索はO(N). N^2で十分.
    // 答えとしてあり得るのは200以下の奇数個. それぞれの判定に必要な計算量がN. という感じ.
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i += 2) {
        int count = 0;
        repg(k, 1, i + 1) {
            if (i % k == 0) count++;
        }
        if (count == 8) ans++;
    }
    cout << ans << endl;
}
