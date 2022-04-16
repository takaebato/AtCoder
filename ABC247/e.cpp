#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> a(N);
    int p1 = 0;
    int p2 = 0;
    ll ans = 0;
    rep(i, N) {
        if (a[p2] > X || a[p2] < Y) {
            p2++;
            p1 = p2;
        } else {
            if (a[p2] == X) fx = 1;
            if (a[p2] == Y) fy = 1;
            if (fx == 1 && fy == 1) {
              ans++;
            }
            while()
        }
    }
}
}
