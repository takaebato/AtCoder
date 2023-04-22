#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      K<=N<=15, ai<=10^9.
      BF: 探索はN個をいくらでも増やせるため、愚直だと無限通り存在する. 判定は愚直でN^2で行ける.
      答えとしてあり得る：どのような増やし方であれ、最終的にNCKの選び方のK個が見えている状態に帰着する.
        そしてそのK個を見えるようにするまでの過程はおそらく一意に定まる.自分より前の最大値より1高くするという単純な貪欲法で行けるはず.＝一部固定で計算で導ける.
      無駄は多いがbit全探索で、2^15*15^2=3*10^4*2*10^2=10^6 で意外と難なく行けそう.
      NCKでもKが大きいとその分のループが必要になり実装がかなり大変になる。これをbit全探索でpopcountにするのはだいぶアリ.
    */
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    ll ans = LLONG_MAX;
    rep(i, 1 << N) {
        if (__builtin_popcount(i) != K) continue;
        vector<int> cp = a;
        ll cost = 0;
        rep(k, N) if (i & (1 << k)) {
            int tmax = 0;
            repg(l, 0, k) tmax = max(tmax, cp[l]);
            if (tmax >= cp[k]) {
                cost += tmax - cp[k] + 1;
                cp[k] = tmax + 1;
            }
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
}
