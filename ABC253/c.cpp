#include <bits/stdc++.h>
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

int main() {
    /*
      heapだと任意の要素が消せないことに気づいて方針変更。
      set, multisetが普通に上位互換なんじゃないかと思えた。定数倍遅いらしいが。
      そして、キャッシュとして10^9の大きさのメモリを確保しようとしてRE出してしまった。普通にmap使うべきケースだった。
      そしてmap使わないでも間に合うらしい。c回のループとか発生するからリスク高そうではあるが。
    */
    int Q;
    cin >> Q;
    set<int> ms;
    map<int, int> m;
    rep(i, Q) {
        int num;
        cin >> num;

        if (num == 1) {
            int x;
            cin >> x;
            ms.insert(x);
            if (m.find(x) != m.end())
                m[x] += 1;
            else
                m.insert(make_pair(x, 1));
        } else if (num == 2) {
            int x, c;
            cin >> x >> c;
            if (c >= m[x]) {
                m[x] = 0;
                ms.erase(x);
            } else {
                m[x] -= c;
            }
        } else {
            cout << *ms.rbegin() - *ms.begin() << endl;
        }
    }
}

// int main() {
//     int Q;
//     cin >> Q;
//     priority_queue<int, vector<int>, greater<int>> maxH;
//     priority_queue<int, vector<int>, less<int>> minH;
//     vec<int> hm(2e9, 0);
//     rep(i, Q) {
//         int num;
//         cin >> num;
//         if (num == 1) {
//             int x;
//             cin >> x;
//             maxH.push(x);
//             minH.push(x);
//             hm[x] += 1;
//         } else if (num == 2) {
//             int x, c;
//             cin >> x >> c;

//             int rem = min(c, hm[x]);
//             rep(k, rem) {
//                 maxH.pop(x);
//                 minH.pop(x);
//                 if (hm[x] > 0) hm[x]--;
//             }
//         } else {
//             cout << maxH.top() - minH.top() << endl;
//         }
//     }
// }
