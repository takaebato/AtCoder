#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int p[5001][5001];

int main() {
    // n<=3*10^3, x,y<=5*10^3.
    // 選び方: nC4で10^13程度.
    // 答えとしてあり得る: で絞り込むのは難しい. 全部あり得るといえばあり得る. 判定しないとわからないか.
    // 一部で他が決まる: 3つ決まると他の一つは決まる. 2つでも、3通りに決まる。よって、探索はnC2で10^6の定数倍程度でいける。
    //   -> 実際は、全ての組み合わせを辿るから反時計回りの一通りで十分。それでも4回同じのを見ることになる。
    // 判定は、そこの座標に点があるかどうか、これはメモリを使って配列の要素アクセスにすればO(1)でいける。メモリを使わないと、判定でも線形探索2回してO(n)かかる. 2分探索2回なら一応行けるか。
    int N;
    cin >> N;
    int x, y;
    vector<vector<int>> d(N, vector<int>(2));
    double ans = 0;
    rep(i, N) {
        cin >> x >> y;
        p[x][y] = 1;
        d[i][0] = x;
        d[i][1] = y;
    }
    rep(i, N) {
        repg(k, i + 1, N) {
            int x1 = d[i][0] + d[i][1] - d[k][1];
            int y1 = d[i][1] - d[i][0] + d[k][0];
            int x2 = d[k][0] + d[i][1] - d[k][1];
            int y2 = d[k][1] - d[i][0] + d[k][0];
            if (!(x1 < 0 || 5000 < x1 || y1 < 0 || 5000 < y1 || x2 < 0 || 5000 < x2 || y2 < 0 || 5000 < y2)) {
                if (p[x1][y1] == 1 && p[x2][y2] == 1) {
                    ans = max(ans, pow(x1 - x2, 2) + pow(y1 - y2, 2));
                }
            }
        }
    }
    cout << (int)ans << endl;
}
