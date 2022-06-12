#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
#define pb push_back
#define eb emplace_back
#define em emplace
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n + 1); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int P[200005];
int I[200005];
int invI[200005];
int L[200005];
int R[200005];

bool solve(int ps, int pt, int is, int it) {
    int r = P[ps];
    int ir = invI[r];
    if (ir < is || it < ir) return false;

    if (ir - is > 0) {
        L[r] = P[ps + 1] + 1;
        if (!solve(ps + 1, ps + ir - is, is, ir - 1)) return false;
    }
    if (it - ir > 0) {
        R[r] = P[ps + ir - is + 1] + 1;
        if (!solve(ps + ir - is + 1, pt, ir + 1, it)) return false;
    }
    return true;
}

/*
  行きがけと通りがけ。
  通りがけは、たとえば二分探索木で使う。
  行きがけと通りがけは、あるツリーにおいて一意に決まるはず。行きがけと通りがけの対応関係を考える。
  https://atcoder.jp/contests/abc255/editorial/4105
*/
int main() {
    int N;
    cin >> N;
    int x;
    rep(i, N) cin >> x, P[i] = --x;
    rep(i, N) cin >> x, I[i] = --x;
    rep(i, N) invI[I[i]] = i;

    bool res = P[0] == 0 && solve(0, N - 1, 0, N - 1);
    if (!res) {
        cout << -1 << endl;
        return 0;
    }
    rep(i, N) cout << L[i] << " " << R[i] << endl;
}
