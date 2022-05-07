#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    // N<=3*10^4, 選び方の全通りは、NC3で10^12程度になってしまう.
    // 一部の探索で他が一意に決まることもない.
    // ただし、答えとしてあり得る全通りは、0-999の1000通りしかない.
    // よって、1000通りの探索で、各々の判定でN、結果O(10^7)で済む。
    int N;
    string S;
    int cnt = 0;
    cin >> N >> S;
    rep(i, 1000) {
        int c[3] = {i / 100, (i / 10) % 10, i % 10};  // 10^kで割って切り捨てが右kシフト. それを基数の10で割ればそこの桁数が分かる.
        int f = 0;
        rep(k, N) {
            if (S[k] == '0' + c[f]) f++;
            if (f == 3) break;
        }
        if (f == 3) cnt++;
    }
    cout << cnt << endl;
}
