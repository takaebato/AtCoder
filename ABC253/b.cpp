#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int H, W;
    cin >> H >> W;
    vec<pair<int, int>> x;
    rep(i, H) {
        string s;
        cin >> s;
        rep(k, W) {
            if (s[k] == 'o') x.push_back(make_pair(i, k));
        }
    }
    cout << abs(x[0].first - x[1].first) + abs(x[0].second - x[1].second) << endl;
}
