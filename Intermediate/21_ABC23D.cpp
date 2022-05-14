#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

const long long INF = 1LL << 60;

int main() {
    /*
      N<=10^5, Hi,Si<=10^9.
      BF: 選び方はN!. 判定はN.
      答えとしてあり得る：最終得点の通り数の探索とそれがあり得るかの判定.
        最終得点はO(N)で求められる. 高々Hi+N*Siで10^14か. 二分探索して対数スケールにすれば超余裕になる.
          またこのケースで二分探索できるのは、区間が二分されているから。ある高さ以下は可能でそれより大きいと不可能という区間に分かれるから二分探索可能。
          lower_boundでなく自分で二分探索を実装するのが若干むずいか.
        判定は、選んだ高さ以下で全て落とせるかの判定だが、これは貪欲法で解ける。一部決定で残り決まるとも言える。判定はソート分でNlogN.
    */
    int N;
    cin >> N;
    vector<pair<int, int>> vec(N);
    rep(i, N) cin >> vec[i].first >> vec[i].second;
    ll left = 0, right = INF;

    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        vector<ll> t(N);
        bool ok = true;
        rep(i, N) {
            if (mid < vec[i].first)
                ok = false;
            else
                t[i] = (mid - vec[i].first) / vec[i].second;
        }
        sort(t.begin(), t.end());
        rep(i, N) if (t[i] < i) ok = false;
        if (ok)
            right = mid;
        else
            left = mid;
    }
    cout << right << endl;
}
