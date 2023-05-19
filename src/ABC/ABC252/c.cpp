#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
using ve = vector<T>;
template <class T>
using vv = vector<vector<T>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      ACできたが時間かかりすぎた。問題の考察と実装共に時間かかった。
      特にアルゴリズムを使うわけではなく、単純に実装が難しい全探索。
      多重ループのbreakは難しい。breakした後その下の処理が続くことに注意。当たり前だが。
    */
    int N;
    cin >> N;
    ve<string> s(N);
    rep(i, N) cin >> s[i];

    int ans = INT_MAX;
    rep(i, 10) {
        int cnt = 0, num = 0;
        ve<bool> seen(N, false);
        while (cnt < N) {
            rep(l, 10) {
                num++;
                rep(k, N) {
                    if (seen[k] == false && int(s[k][l] - '0') == i) {
                        cnt++;
                        seen[k] = true;
                        break;
                    }
                }
                if (cnt >= N) break;
            }
        }
        ans = min(ans, num - 1);
    }
    cout << ans << endl;
}
