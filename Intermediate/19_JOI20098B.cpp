#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      d<=10^9, n<=10^5, m<=10^4
      各配達先から一番近い店までの距離を求める作業. 線形探索だとm*nで10^9でムリ.
      上手いこと二分探索できればmlognで行けるが、前処理というか一捻り必要だろう.
      -> 円環は延長した配列に保持して、二分探索は昇順と降順それぞれで行う. 降順は各要素に-1かけるとできる. 計算量はO((n+m)logn)
      別解で店と配達先両方並び替えて順番に見ていくのもある. 探索元と先を両方並び替えていると、ソートがひとつ増えはするが、判定が積から和に変わるレベルで改善できる.
    */
    // 自力解. 2回二分探索している. 実際は一回でも行けて見つからないケースも考えなくてOK.
    // int d, N, M;
    // cin >> d >> N >> M;
    // vector<int> ds(N + 1);
    // ds[0] = 0;
    // ds[N] = d;
    // repg(i, 1, N) cin >> ds[i];
    // sort(ds.begin(), ds.end());
    // vector<int> dsi(N + 1);
    // rep(i, N + 1) dsi[i] = ds[i] * -1;
    // sort(dsi.begin(), dsi.end());
    // vector<int> ks(M);
    // rep(i, M) cin >> ks[i];

    // ll ans = 0;
    // rep(i, M) {
    //     int dist = INT_MAX;
    //     auto d1 = lower_bound(ds.begin(), ds.end(), ks[i]);
    //     if (d1 != ds.end()) dist = min(dist, ds[d1 - ds.begin()] - ks[i]);
    //     auto d2 = lower_bound(dsi.begin(), dsi.end(), -1 * ks[i]);
    //     if (d2 != dsi.end()) dist = min(dist, dsi[d2 - dsi.begin()] + ks[i]);
    //     ans += dist;
    // }
    // cout << ans << endl;

    // 2分探索一回で行ける. 逆順で探索せずとも、upper_boundのひとつ前だけ見ればOK. orderは変わらないが実装量がだいぶ少なくて済む.
    int d, N, M;
    cin >> d >> N >> M;
    vector<int> ds(N + 1), ks(M);
    ds[0] = 0;
    ds[N] = d;
    repg(i, 1, N) cin >> ds[i];
    rep(i, M) cin >> ks[i];
    sort(ds.begin(), ds.end());

    ll ans = 0;
    rep(i, M) {
        auto it = upper_bound(ds.begin(), ds.end(), ks[i]) - ds.begin();
        ans += min(ds[it] - ks[i], ks[i] - ds[it - 1]);
    }
    cout << ans << endl;
}
