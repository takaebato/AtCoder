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

    vec<int> a(N);
    rep(i, N) cin >> a[i];

    vec<int> k(4, 0);
    int ans = 0;
    rep(i, N) {
        k[0] = 1;
        repi(j, 4) {
            if (k[j]) {
                if (j + a[i] > 3) {
                    ans++;
                    k[j] = 0;
                } else {
                    k[j + a[i]] = 1;
                    k[j] = 0;
                }
            }
        }
    }
    cout << ans << endl;
}
