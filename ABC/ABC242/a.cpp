#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = j; i < (int)(n); i++)

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    if (X < A + 1) {
        cout << 1 << endl;
        return 0;
    }
    if (B < X) {
        cout << 0 << endl;
        return 0;
    }
    double ans;
    ans = (double)C / (B - A);
    cout << fixed << setprecision(15) << ans << endl;
}
