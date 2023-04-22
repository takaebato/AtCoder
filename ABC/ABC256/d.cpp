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

int main() {
    int N;
    cin >> N;
    vec<P<int, int>> range(N);
    rep(i, N) {
        int l, r;
        cin >> l >> r;
        range.eb(l, r);
    }
    sort(range.begin(), range.end());

    vec<int> ans(N, 0);
    int tmp1 = 0;
    rep(i, N - 1) {
        if (range[i].first != range[i + 1].first) {
            tmp1 = i + 1;
            ans[i + 1] = 1;
        }
    }

    repg(i, tmp1, N) {
        int idx = i + 1;
        int tmp = i;
        int cnt = 0;
        while (range[idx].first <= range[i].second) {
            if (range[tmp].second < range[idx].second) {
                tmp = idx + 1;
                idx++;
                if (idx >= N) break;
            }
            cnt++;
        }
        ans[tmp] = 1;
        cnt--;
        i += cnt;
    }
    cout <<
}
