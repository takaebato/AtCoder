#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = j; i < (int)(n); i++)

int main() {
    int N, K, X;
    cin >> N >> K >> X;
    vector<int> a(N, 0);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    rep(i, N) {
        if (K == 0) break;
        while (a[i] >= X) {
            a[i] -= X;
            K--;
            if (K == 0) break;
        }
    }
    ll sum = 0;
    if (K == 0) {
        rep(i, N) sum += max(a[i], 0);
        cout << sum << endl;
        return 0;
    }

    sort(a.begin(), a.end(), greater<int>());
    rep(i, N) {
        if (K == 0) break;
        a[i] -= X;
        K--;
    }
    rep(i, N) sum += max(a[i], 0);
    cout << sum << endl;
}
