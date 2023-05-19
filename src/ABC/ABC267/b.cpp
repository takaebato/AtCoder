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
    string s;
    cin >> s;
    vvec<char> v(7, vec<char>());
    v[0].pb(s[6]);
    v[1].pb(s[3]);
    v[2].pb(s[1]);
    v[2].pb(s[7]);
    v[3].pb(s[0]);
    v[3].pb(s[4]);
    v[4].pb(s[2]);
    v[4].pb(s[8]);
    v[5].pb(s[5]);
    v[6].pb(s[9]);
    if (s[0] == '1') {
        cout << "No" << endl;
        return 0;
    }
    rep(i, 7) {
        bool iok = false;
        rep(j, v[i].size()) if (v[i][j] == '1') iok = true;
        if (!iok) continue;
        repg(j, i + 2, 7) {
            bool jok = false;
            rep(k, v[j].size()) if (v[j][k] == '1') jok = true;
            if (!jok) continue;
            repg(k, i + 1, j) {
                bool kok = true;
                rep(l, v[k].size()) if (v[k][l] == '1') kok = false;
                if (kok) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}
