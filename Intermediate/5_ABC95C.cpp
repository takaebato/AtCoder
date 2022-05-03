#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    // 1≤A,B,C≤5000 1≤X,Y≤10^5
    // 本当に愚直な全探索では、答えとしてあり得る通り数で10^5^3になる。が二つ決めれば一つ決まるため、10^5^2にはできる。
    // ここでさらに、条件的にABを決めるとAとBも決まるため、結局10^5の探索で十分になる.
    // いわゆる、一部の探索で他が一意に定まる場合になる。
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int x = 0;
    int y = 0;
    int z = 0;
    int ans = INT_MAX;

    while (1) {
        if (max(X, Y) < z / 2) break;
        x = max(X - z / 2, 0);
        y = max(Y - z / 2, 0);
        ans = min(ans, A * x + B * y + C * z);
        z++;
    }
    cout << ans << endl;
}
