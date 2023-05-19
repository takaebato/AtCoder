#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
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
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

const int MOD = 1000000007;
/*
  冪乗計算。
  nを2進数変換して計算すれば、計算回数をO(log(n))にできる。
*/
int main() {
    ll m, n;
    cin >> m >> n;
    ll res = 1;

    while (n > 0) {
        if (n & 1) res = res * m % MOD;
        m = m * m % MOD;
        n >>= 1;
    }
    cout << res << endl;
}
