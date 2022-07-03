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
    int n;
    cin >> n;
    vec<P<int, int>> st;
    int pre;
    rep1(i, n) {
        int c;
        cin >> c;
        if (st.empty()) {
            st.eb(c, i);
            pre = c;
            continue;
        }
        if (c != pre) {
            if ((i % 2) == 1) {
                st.eb(c, i);
            } else {
                if (st.size() == 1) {
                    st[0].first = 1 - st[0].first;
                } else {
                    st.pop_back();
                }
            }
        }
        pre = c;
    }

    int id = 1;
    int ans = 0;
    rep(i, st.size()) {
        if (st[i].first == 0)
            id = st[i].second;
        else
            ans += st[i].second - id;
    }
    if (st[st.size() - 1].first == 0) ans += n + 1 - st[st.size() - 1].second;

    cout << ans << endl;
}
