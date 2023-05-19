#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
template <class T, class U>
using P = pair<T, U>;
#define pb push_back
#define eb emplace_back
#define em emplace
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n + 1); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int Ha, Wa;
    cin >> Ha >> Wa;
    vvec<int> a(Ha, vec<int>(Wa));
    rep(i, Ha) rep(j, Wa) cin >> a[i][j];
    int Hb, Wb;
    cin >> Hb >> Wb;
    vvec<int> b(Hb, vec<int>(Wb));
    rep(i, Hb) rep(j, Wb) cin >> b[i][j];

    bool ans = false;
    rep(i, 1 << Ha) {
        if (__builtin_popcount(i) != Hb) continue;
        rep(j, 1 << Wa) {
            if (__builtin_popcount(j) != Wb) continue;
            int ix = 0, iy = 0;
            bool ok = true;
            rep(k, Ha) {
                rep(l, Wa) {
                    if ((i & (1 << k)) && (j & (1 << l))) {
                        if (a[k][l] != b[ix][iy]) ok = false;
                        iy++;
                    }
                }
                if (!ok) break;
                if (i & (1 << k)) ix++;
                iy = 0;
            }
            if (ok) ans = true;
        }
    }

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
