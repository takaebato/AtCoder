#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      R<=10, C<=10^4
      BF: 全通りは横の裏返し方と縦の裏返し方=2^R*2^C=2^(10^4)で大爆発. 判定は最後に一回線形で見ればいいから10^5程度か.
      答えとしてあり得る：多分絞れない。
      一部決定で残りが決まる：rowを決めると、各columnを選択すべきかどうかは計算で決められる。要は、いくつかを選ぶのbit全探索をせずとも計算で各々決められる。
      ただ単純にやると、探索で2^10, 判定で10*10^4だから、合計で10^8必要. ギリ行けるか？という計算量か.
    */

    // 自力解. bitマスクを使いこなせていないからだいぶ遅め.ギリ通ったくらい.
    // int R, C;
    // cin >> R >> C;
    // vector<vector<int>> vec(R, vector<int>(C));
    // rep(i, R) rep(k, C) cin >> vec[i][k];
    // int ans = 0;
    // for (int i = 0; i < (1 << R); i++) {
    //     vector<vector<int>> cp = vec;
    //     rep(k, R) if (i & (1 << k)) rep(l, C) cp[k][l] ^= 1;
    //     rep(k, C) {
    //         int c0 = 0;
    //         int c1 = 0;
    //         rep(l, R) {
    //             if (cp[l][k] == 0) {
    //                 c0++;
    //             } else {
    //                 c1++;
    //             }
    //         }
    //         if (c1 > c0) rep(l, R) cp[l][k] ^= 1;
    //     }
    //     int cnt = 0;
    //     rep(k, R) rep(l, C) if (cp[k][l] == 0) cnt++;
    //     ans = max(ans, cnt);
    // }
    // cout << ans << endl;

    // bit演算で、popcountによるRカウントの高速化. 10を1にする程度？
    // columnは桁数が多すぎるからllでも保持できない. bitsetではCで桁数調整できないから、popcountとか厳しいか？というかそれだと結局カウント必要で効率化できないか？
    int R, C;
    cin >> R >> C;
    vector<int> col(C, 0);
    rep(i, R) rep(k, C) {
        int x;
        cin >> x;
        if (x) col[k] |= 1 << i;
    }
    int ans = 0;
    rep(mask, 1 << R) {
        int cur = 0;
        rep(k, C) {
            int pp = __builtin_popcount(col[k] ^ mask);
            cur += max(pp, R - pp);
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
}
