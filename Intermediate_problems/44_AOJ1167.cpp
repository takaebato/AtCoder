#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
template <class T>
using P = pair<T, T>;
#define pb push_back
#define eb emplace_back
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      正四面体数＝n(n+1)(n+2)⁄6、N<10^6より、nは10^2程度に収まる。
      各正四面体数をx1, x2, ...として、
      dp[i]=合計値がiとなる正四面体数の最小値 とすると、
      dp[i]=min(dp[i-x1], dp[i-x2], ...) + 1
      で求められる.
      奇数のみのケースは、xiのうち奇数のものを最初に選んでおいて、それで同様にdpを算出すればOK。
      事前に求めるとして、計算量は10^6*100程度かかってしまうが、ギリいけるか。
    */
    vec<int> dpa(2e6, INT_MAX);
    vec<int> dpo(2e6, INT_MAX);
    vec<int> al, od;
    int num = 0;
    int cnt = 1;
    while (1) {
        num = cnt * (cnt + 1) * (cnt + 2) / 6;
        if (num > 1e6) break;
        al.eb(num);
        if (num % 2 == 1) od.eb(num);
        cnt++;
    }
    dpa[0] = 0;
    dpo[0] = 0;

    rep(i, 1e6 + 1) {
        rep(j, al.size()) dpa[i + al[j]] = min(dpa[i + al[j]], dpa[i] + 1);
        rep(j, od.size()) dpo[i + od[j]] = min(dpo[i + od[j]], dpo[i] + 1);
    }

    int q;
    while (cin >> q) {
        if (q == 0) return 0;
        printf("%d %d\n", dpa[q], dpo[q]);
    }
}
