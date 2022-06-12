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

// ll fact(int n) {
//     ll tmp = 1;
//     repg(i, 1, n + 1) tmp *= i;
//     return tmp;
// }

int main() {
    /*
      1. 組み合わせの条件のパターンを整理していきたい。
         今回は、重複数字はあるが、indexが異なる（別の場所にある）ものは別でカウントするケース。
         当然、全ての数字はindexが異なるから、全ての数字は区別されている状態。
         条件として、3つ取り出したうちに同じ数字がないこと。

      2. 組み合わせの計算によっても解ける。
         全組み合わせNC3から、種類数が1または2の通り数を引けばいい。
         状態遷移、場合分けになる。
         NC3-(2種類のみの通り数、1種類のみの通り数)
      3. dpによる解法
    */
    int N;
    cin >> N;
    ve<int> a(N);
    rep(i, N) cin >> a[i];
    ve<int> vec(1e6, 0);
    rep(i, N) vec[a[i]]++;
    ll num = N;
    rep(i, vec.size()) {
        if (vec[i] > 1) num -= (vec[i] - 1);
    }
    ll ans = 0;
    rep(i, vec.size()) { ans += ((fact(num) - fact(num - 1)) * vec[i]); }
    cout << ans << endl;
}
