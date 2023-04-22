#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    // 外堀から埋めようとして考慮もれガッツリ発生させてWAした. 見たい部分が決まっているのだからその周辺だけを見ればいい.

    // コンテスト時の解. OK.
    int H, W, R, C;
    cin >> H >> W >> R >> C;
    int ans = 0;
    if (R - 1 > 0) ans++;
    if (R + 1 <= H) ans++;
    if (C - 1 > 0) ans++;
    if (C + 1 <= W) ans++;
    cout << ans << endl;
}
