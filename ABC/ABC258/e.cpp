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
    int N, Q, X;
    cin >> N >> Q >> X;
    vec<int> w(N);
    rep(i, N) cin >> w[i];
    vec<P<int, int>> a(N, P<int, int>({1e6, 0}));
    int re = 0;
    int offset = 0;
    rep(i, N) {
        if (a[i].first != 1e6) {
            re = i - a[i].first;
            offset = a[i].first - 1;
        }
        a[i].first = i;
        ll sum = 0;
        int id = i;
        while (X > sum) {
            sum += w[id % N];
            a[i].second++;
            id++;
        }
        i += id - 1;
    }
    sort(a.begin(), a.end());
    rep(qi, Q) {
        ll k;
        cin >> k;
        ll num;
        if (k <= offset) {
            cout << a[k - 1].second << endl;
        } else {
            num = (k - offset - 1) % re;
            cout << a[offset + num].second << endl;
        }
    }
}
