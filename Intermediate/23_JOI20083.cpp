#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      N<=10^3, M<=2*10^8, Pi<=10^8（Nが小さいからN^2はいけそうという第一印象）
      BF: 探索がNC4で10^12程度。判定はO(1)か。
      答えとしてあり得る： 最大得点がMだから二分探索は余裕だが、区間が二つに分かれているわけではないから無理か。
      一部決定で他決まる：3つ決まればあと一つは二分探索で決まる。
        というか、これはやはり選択肢が4つで対称性があり、かつN^2は行けるところを見ると、N^2とN^2の問題に変換するのが定石か。
        一部決定として片方のN^2を決めた時に、残りを二分探索で探すから、O(N^2log(N^2))で行ける。
        広義単調増加性もあるから尺取でもいけるはず。
    */
    int N, M;
    cin >> N >> M;
    vector<ll> p(N);
    rep(i, N) cin >> p[i];
    sort(p.begin(), p.end());
    ll ans = 0;
    // 1
    auto it = upper_bound(p.begin(), p.end(), M) - p.begin();
    if (it != 0) ans = max(ans, p[it - 1]);
    // 2
    rep(i, N) {
        if (p[i] > M) continue;
        auto it = upper_bound(p.begin(), p.end(), M - p[i]) - p.begin();
        if (it != 0) ans = max(ans, p[it - 1] + p[i]);
    }
    // 3
    vector<ll> p2;
    rep(i, N) rep(k, N) p2.push_back(p[i] + p[k]);
    sort(p2.begin(), p2.end());
    rep(i, N) {
        if (p[i] > M) continue;
        auto it = upper_bound(p2.begin(), p2.end(), M - p[i]) - p2.begin();
        if (it != 0) ans = max(ans, p2[it - 1] + p[i]);
    }
    // 4
    rep(i, pow(N, 2)) {
        if (p2[i] > M) continue;
        auto it = upper_bound(p2.begin(), p2.end(), M - p2[i]) - p2.begin();
        if (it != 0) ans = max(ans, p2[it - 1] + p2[i]);
    }
    cout << ans << endl;
}
