#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int N;
    cin >> N;
    vector<string> a(N);

    rep(i, N) {
        int t;
        cin >> t;

        string tmp = "1";
        if (t != 0) rep(k, t) tmp += "0";

        if (i == 0) {
            a[i] = tmp;
            continue;
        }

        reverse(a[i - 1].begin(), a[i - 1].end());
        reverse(tmp.begin(), tmp.end());
        if (tmp.size() <= a[i - 1].size()) {
            if (tmp.size() < a[i - 1].size()) {
                bool flag2 = false;
                if (a[i - 1][t] == '0') flag2 = true;
                repg(k, t + 1, a[i - 1].size()) {
                    if (a[i - 1][k] == '0' && flag2 == false) {
                        tmp += "1";
                        flag2 = true;
                    } else if (k != a[i - 1].size() - 1 || flag2 == false) {
                        tmp += '0';
                    } else if (flag2 == true) {
                        tmp += a[i - 1][k];
                    }
                }
                if (flag2 == false) tmp += '1';
            } else if (tmp.size() == a[i - 1].size()) {
                tmp += '1';
            }
        }
        reverse(a[i - 1].begin(), a[i - 1].end());
        reverse(tmp.begin(), tmp.end());
        a[i] = tmp;
    }
    rep(i, N) cout << a[i] << endl;
    ll ans = 0;
    reverse(a[N - 1].begin(), a[N - 1].end());
    rep(i, a[N - 1].size()) if (a[N - 1][i] == '1') ans += pow(2, i);
    cout << ans << endl;
}
