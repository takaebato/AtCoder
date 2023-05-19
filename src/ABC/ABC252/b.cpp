#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
using ve = vector<T>;
template <class T>
using vv = vector<vector<T>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      OK
    */
    int N, K;
    cin >> N >> K;
    ve<int> a(N), b(K);
    rep(i, N) cin >> a[i];
    rep(i, K) cin >> b[i];

    int ma = 0;
    rep(i, N) ma = max(ma, a[i]);
    rep(i, K) if (a[b[i] - 1] == ma) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
