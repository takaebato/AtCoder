#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      N<=8.
      BF: PとQが何番目かを求める探索で順列でN!. 判定はN. これも愚直で十分.
    */
    int N;
    cin >> N;
    vector<int> p(N);
    vector<int> q(N);
    rep(i, N) cin >> p[i];
    rep(i, N) cin >> q[i];
    vector<int> vec(N);
    rep(i, N) vec[i] = i + 1;
    int cnt = 0;
    int a = 0;
    int b = 0;
    do {
        cnt++;
        bool same = true;
        rep(i, N) if (vec[i] != p[i]) same = false;
        if (same) a = cnt;
        same = true;
        rep(i, N) if (vec[i] != q[i]) same = false;
        if (same) b = cnt;
    } while (next_permutation(vec.begin(), vec.end()));
    cout << abs(a - b) << endl;
}
