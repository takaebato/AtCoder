#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    // マス:10^9, N:30,
    // 選び方：探索は入口と出口で10^9^2=10^18. 判定は30*4程度.
    // 答えであり得るケース：ai<=biだから、
    // 答えとしてあり得るのが、aiかbiというのがこれは分かるのか？なぜそう言えるのか？

    // int N;
    // cin >> N;
    // vector<vector<int>> ab(N, vector<int>(2));
    // int minA = INT_MAX;
    // int maxB = 0;
    // rep(i, N) {
    //     cin >> ab[i][0] >> ab[i][1];
    //     minA = min(minA, ab[i][0]);
    //     maxB = max(maxB, ab[i][1]);
    // }
    // cout << (maxB - minA) * N << endl;
}
