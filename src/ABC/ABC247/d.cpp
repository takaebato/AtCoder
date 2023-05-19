#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int Q;
    cin >> Q;
    int num;
    ll c;
    int p1 = 0;
    int p2 = 0;
    vector<vector<ll>> a(2 * Q, vector<ll>(2));
    rep(i, Q) {
        cin >> num;
        if (num == 1) {
            cin >> a[p1][0] >> a[p1][1];
            p1++;
        } else if (num == 2) {
            ll sum = 0;
            cin >> c;
            while (c >= 0) {
                if (a[p2][1] >= c) {
                    sum += a[p2][0] * c;
                    a[p2][1] -= c;
                    cout << sum << endl;
                    break;
                } else {
                    sum += a[p2][0] * a[p2][1];
                    c -= a[p2][1];
                    p2++;
                }
            }
        }
    }
}
