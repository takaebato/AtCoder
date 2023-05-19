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
    unordered_map<char, int> mp = {{'a', 1}, {'t', 2}, {'c', 3}, {'o', 4}, {'d', 5}, {'e', 6}, {'r', 7}};

    string s;
    cin >> s;
    vec<int> a;
    for (char c : s) a.pb(mp[c]);

    const int N = 7;
    int cnt = 0;
    rep(i, N) {
        bool flag = false;
        rep(j, N - 1) {
            if (a[j] > a[j + 1]) {
                flag = true;
                swap(a[j], a[j + 1]);
                cnt++;
            }
        }
        if (!flag) break;
    }
    cout << cnt << endl;
}
