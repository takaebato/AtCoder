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

/*
  D==0のケース見落としてREになった。
  エッジケースの入力値は見ないといけない。
*/
int main() {
    ll X, A, D, N;
    cin >> X >> A >> D >> N;
    ll ma, mi;
    if (D > 0) {
        ma = A + D * (N - 1);
        mi = A;
    } else {
        ma = A;
        mi = A + D * (N - 1);
    }

    if (X >= ma) {
        cout << X - ma << endl;
    } else if (X <= mi) {
        cout << mi - X << endl;
    } else {
        cout << min((X - mi) % abs(D), abs(D) - ((X - mi) % abs(D))) << endl;
    }
}
