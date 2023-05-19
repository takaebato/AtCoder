#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    // クエリ問題. 定石通り、データ構造を上手く使ってアクセス速度を上げて、毎クエリの計算量を削減する.
    // 線形探索O(N)から配列アクセスO(1)へ効率化して行けた.

    // コンテスト時の解. 実装はちょっと汚いが考え方や方針は模範解答通りだったと思う.
    // int N, Q;
    // cin >> N >> Q;
    // vector<int> vecv(N), veci(N);
    // rep(i, N) vecv[i] = i;
    // rep(i, N) veci[i] = i;
    // rep(i, Q) {
    //     int q;
    //     cin >> q;
    //     q -= 1;
    //     int idx = veci[q];
    //     if (idx != N - 1) {
    //         vecv[idx] = vecv[idx + 1];
    //         vecv[idx + 1] = q;
    //         veci[vecv[idx]] = idx;
    //         veci[q] = idx + 1;
    //     } else {
    //         vecv[idx] = vecv[idx - 1];
    //         vecv[idx - 1] = q;
    //         veci[vecv[idx]] = idx;
    //         veci[q] = idx - 1;
    //     }
    // }
    // rep(i, N) cout << vecv[i] + 1 << " ";
    // cout << "\n";

    // リファクタリング
    int N, Q;
    cin >> N >> Q;
    vector<int> val(N), pos(N);
    rep(i, N) val[i] = i, pos[i] = i;
    rep(i, Q) {
        int q;
        cin >> q;
        int p0 = pos[q - 1];
        int p1 = p0;
        if (p0 != N - 1) {
            p1++;
        } else {
            p1--;
        }
        int v0 = val[p0];
        int v1 = val[p1];
        swap(val[p0], val[p1]);
        swap(pos[v0], pos[v1]);
    }
    rep(i, N) {
        if (i != 0) cout << ' ';
        cout << val[i] + 1;
    }
    cout << endl;
}
