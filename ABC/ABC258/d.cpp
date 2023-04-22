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
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int N, X;
    cin >> N >> X;
    vvec<int> t(N, vec<int>(2, 0));
    rep(i, N) cin >> t[i][0] >> t[i][1];
    ll sum = 0;
    ll to = LLONG_MAX;
    int mi = INT_MAX;
    rep(i, N) {
        sum += t[i][0] + t[i][1];
        mi = min(mi, t[i][1]);
        to = min(to, sum + (ll)mi * (X - 1 - i));
        if (X - 1 - i == 0) break;
    }
    cout << to << endl;
}
