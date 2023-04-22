#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

// int dp[310][310];
// int w[310];

// int rec(int l, int r) {
//     if (r - l < 2) return 0;
//     if (r - l == 2) return dp[l][r];

//     int res = 0;

//     if (dp[l + 1][r] != -1)
//         res = max(res, dp[l + 1][r]);
//     else
//         res = max(res, rec(l + 1, r));

//     repg(i, l + 2, r + 2) {
//         int tmp = 0;

//         if (dp[l + 1][i] != -1)
//             tmp = dp[l + 1][i];
//         else
//             tmp = rec(l + 1, i);

//         if (tmp != (i - l - 1)) continue;

//         if (dp[i + 1][r] != -1)
//             tmp = dp[i + 1][r];
//         else
//             tmp = rec(i + 1, r);

//         res = max(res, (i - l + 1 + tmp));
//     }

//     return res;
// }

int main() {
    /*
      全通りは階乗の2つずつ減る版みたいな感じだろうか。
      区間DPとして考える。
      dp[l][r]=区間[l, r)での落とせる数の最大値
      とおいたとして、遷移をどうするか。
      独立な部分問題、排反事象として分けたい。
      [l, r)での打ち消し合いとしてあり得るケースは、
        lが残る、lがl+1と打ち消し合う、lがl+2と打ち消し合う ... lがr-1と打ち消し合う
      という排反事象に分けられる。
      よって、これらのmaxをとればいい。
      lが残る->dr[l+1][r]
      lが k in l+1..r と打ち消し合う -> あり得なければスキップ、あり得るなら考える。あり得る場合は、|l-k|<=1かつdp[l+1][k-1]=k-l-1(要は間が全て打ち消し合う場合)の時で、その時の数はk-l+1になる。
      まああり得ない場合も考えても一応構わないのかもしれない。それは他のケースを重複して考えることになるだけか。lが残るケースまたは、lがm(<k)と打ち消し合うケースに含まれるはず。
    */
    // int n;
    // cin >> n;
    // repg(i, 1, n + 1) cin >> w[i];
    // memset(dp, -1, sizeof(dp));
    // repg(i, 1, n) if (abs(w[i] - w[i + 1] <= 1)) dp[i][i + 2] = 2;
    // cout << rec(1, n + 1) << endl;

    int n;
    cin >> n;
    vec<int> w(n);
    cin >> w[i];
    vvec<int> dp(N + 1, vec<int>(N + 1, -1));
    rep(i,N+1){
      dp[i][i]=0;
      if(i<N)dp[i][i+1]=0;
    }
}
