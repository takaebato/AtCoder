#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = j; i < (int)(n); i++)

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    vector<ll> b = a;
    sort(b.begin(), b.begin() + K);

    map<ll, int> m;
    rep(i, K) m.insert(make_pair(a[i], i));

    int dmin = 1000000;
    int l = 0;
    repg(i, K, N) {
        while (a[m.at(b[l])] < a[i]) {
            dmin = min(dmin, i - m.at(b[l]));
            l++;
            if (l > K - 1) break;
            if (b[l] == b[l - 1]) l++;
            if (l > K - 1) break;
        }
        if (l > K - 1) break;
    }

    if (dmin == 1000000) {
        cout << -1 << endl;
    } else {
        cout << dmin << endl;
    }
}
