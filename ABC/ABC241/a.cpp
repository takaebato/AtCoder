#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = j; i < (int)(n); i++)

int main() {
    vector<int> a(10);
    rep(i, 10) cin >> a[i];
    int ans = a[0];
    rep(i, 2) { ans = a[ans]; }
    cout << ans << endl;
}
