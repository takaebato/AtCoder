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
    int N;
    cin >> N;
    string s;
    cin >> s;
    vec<int> w(N);
    rep(i, N) cin >> w[i];
    vec<P<int, int>> pa(N);
    int num0 = 0;
    int num1 = 0;
    rep(i, N) {
        pa[i] = {w[i], s[i] - '0'};
        if (s[i] == '0')
            num0++;
        else
            num1++;
    }
    sort(pa.begin(), pa.end());

    map<int, P<int, int>> ma;
    rep(i, N) {
        if (pa[i].second == 0) {
            if (ma.find(pa[i].first) == ma.end()) {
                ma[pa[i].first] = {1, 0};
            } else {
                ma[pa[i].first].first++;
            }
        } else {
            if (ma.find(pa[i].first) == ma.end()) {
                ma[pa[i].first] = {0, 1};
            } else {
                ma[pa[i].first].second++;
            }
        }
    }

    int cnt0 = 0;
    int cnt1 = 0;
    int ans = 0;
    for (auto el : ma) {
        ans = max(ans, cnt0 + (num1 - cnt1));
        cnt0 += el.second.first;
        cnt1 += el.second.second;
    }
    ans = max(ans, num0);
    ans = max(ans, num1);

    cout << ans << endl;
}
