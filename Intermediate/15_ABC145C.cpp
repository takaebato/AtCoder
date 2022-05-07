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
      BF: 探索でN!. 判定で2N程度か. これは基本問題だから愚直でいける.
    */
    int N;
    cin >> N;
    vector<pair<int, int>> p(N);
    rep(i, N) cin >> p[i].first >> p[i].second;
    double dist = 0;
    int cnt = 0;
    sort(p.begin(), p.end());
    do {
        repg(i, 1, N) dist += (double)sqrt(pow(p[i].first - p[i - 1].first, 2) + pow(p[i].second - p[i - 1].second, 2));
        cnt++;
    } while (next_permutation(p.begin(), p.end()));
    cout << fixed << setprecision(10) << dist / cnt << endl;
}
