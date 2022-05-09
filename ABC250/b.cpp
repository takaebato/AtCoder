#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    // これは難しいよ. だいぶ時間かかった。 ループを何重も書くのもむずいし、白か黒かの判定がタイルの行と列の和を2で割った余りで場合分けできるとか、いやむずい。

    // コンテスト時の解. OK.
    int N, A, B;
    cin >> N >> A >> B;
    int col = 1;
    rep(i, N) {
        rep(k, A) {
            rep(l, N) {
                rep(m, B) {
                    if ((i + l) % 2 == 0) {
                        cout << '.';
                    } else {
                        cout << '#';
                    }
                }
            }
            cout << "\n";
        }
    }
}
