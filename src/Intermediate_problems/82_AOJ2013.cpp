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
    auto toV = [=](string s) {
        int val = 0;
        for (int i = 0; i < s.size(); i++) {
            val *= 10;
            val += s[i] - '0';
        }
        return val;
    };
    auto toS = [=](string s) {
        int h = toV(s.substr(0, 2)) * 60 * 60;
        int m = toV(s.substr(3, 2)) * 60;
        int se = toV(s.substr(6, 2));
        return h + m + se;
    };

    int n;
    while (cin >> n) {
        if (n == 0) break;

        vec<int> im(60 * 60 * 24 + 1, 0);  // 番兵分のラスト+1は必要
        // [a, b) 開区間のケース
        rep(i, n) {
            string a, b;
            cin >> a >> b;
            im[toS(a)]++;
            im[toS(b)]--;
        }
        int ans = 0;
        rep(i, 60 * 60 * 24) {
            im[i + 1] += im[i];
            ans = max(ans, im[i]);
        }
        cout << ans << endl;
    }
}
