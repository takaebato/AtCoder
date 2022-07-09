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

vector<pair<char, int>> rle(const string& s) {
    vector<pair<char, int>> res;
    if (s.size() == 0) return res;

    res.eb(s[0], 1);
    int id = 0;
    repg(i, 1, s.size()) {
        if (s[i] == s[i - 1]) {
            res[id].second++;
        } else {
            res.eb(s[i], 1);
            id++;
        }
    }
    return res;
}

string rld(vector<pair<char, int>>& code) {
    string res;
    for (auto p : code) rep(i, p.second) res.pb(p.first);
    return res;
}

string rleToS(string& s) {
    string res;
    if (s.size() == 0) return res;

    res.pb(s[0]);
    int cnt = 1;
    repg(i, 1, s.size()) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            res.append(to_string(cnt));
            res.pb(s[i]);
            cnt = 1;
        }
    }
    res.append(to_string(cnt));
    return res;
}

int main() {
    string s, t;
    cin >> s >> t;
    vec<P<char, int>> cnt_s, cnt_t;

    // sとtをそれぞれランレングス圧縮する
    cnt_s = rle(s);
    cnt_t = rle(t);

    // 以下、問題特有の判定条件
    if (cnt_s.size() != cnt_t.size()) {
        cout << "No" << endl;
        return 0;
    }

    bool ok = true;
    rep(i, cnt_s.size()) {
        if (cnt_s[i].first != cnt_t[i].first) {
            ok = false;
        } else if (cnt_t[i].second < cnt_s[i].second) {
            ok = false;
        } else if (cnt_t[i].second > cnt_s[i].second && cnt_s[i].second < 2) {
            ok = false;
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
