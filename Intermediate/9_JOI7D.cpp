#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      m<200, n<1000, x,y<10^6.
      全通り：探索はn. 判定はm. だから2*10^5. 十分いける. （本当の愚直BFは、探索だけでnCmかもしれない. もしくは全ての平行移動の方法として全ての点を試すで10^6^2かもしれない.）
      ただ、メモリが10^6^2を持てない → 判定は二分探索2回でm*2lognで行くか.
      * まとめ
      1. 答えとしてあり得るケースで、ある一点をn個だけ遷移させる. 存在しない点を試す必要はない.
      2. 一つ決定で他が決まるケース。
      - 一つ決めたら残りのm-1の相対位置が決まるため、探索はnでおわる。
      - で、判定でextra memory or 二分探索. ハッシュテーブルでも二分探索でも行ける。2次元配列は厳しい。
    */

    // ソートして判定を減らす. O(n^2). 愚直にやるとO(n^2m)だが、ソートしておくと線形探索一回で済ませられる. pairは二次元でもソートできることは重要.
    // int m, n;
    // cin >> m;
    // vector<pair<int, int>> from(m);
    // rep(i, m) cin >> from[i].first >> from[i].second;
    // cin >> n;
    // vector<pair<int, int>> to(n);
    // rep(i, n) cin >> to[i].first >> to[i].second;

    // sort(from.begin(), from.end());
    // sort(to.begin(), to.end());

    // rep(i, n) {
    //     int pos = 1;
    //     int disX = to[i].first - from[0].first;
    //     int disY = to[i].second - from[0].second;
    //     repg(k, i + 1, n) {
    //         if (from[pos].first + disX == to[k].first && from[pos].second + disY == to[k].second) {
    //             pos++;
    //             if (pos == m) {
    //                 cout << disX << " " << disY << endl;
    //                 return 0;
    //             }
    //         }
    //     }
    // }

    // 二分探索. O(nmlogn)
    int m, n;
    cin >> m;
    vector<pair<int, int>> from(m);
    rep(i, m) cin >> from[i].first >> from[i].second;
    cin >> n;
    vector<pair<int, int>> to(n);
    rep(i, n) cin >> to[i].first >> to[i].second;

    sort(from.begin(), from.end());
    sort(to.begin(), to.end());

    rep(i, n) {
        int pos = 1;
        int disX = to[i].first - from[0].first;
        int disY = to[i].second - from[0].second;
        rep(k, m - 1) {
            auto found = binary_search(to.begin(), to.end(), make_pair(from[pos].first + disX, from[pos].second + disY));
            if (found) {
                pos++;
                if (pos == m) {
                    cout << disX << " " << disY << endl;
                    return 0;
                }
            }
        }
    }
}
