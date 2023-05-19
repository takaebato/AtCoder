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
    vector<vector<string>> s(N, vector<string>(2));
    rep(i, N) { cin >> s[i][0] >> s[i][1]; }
    rep(i, N) {
        bool ok1 = true;
        bool ok2 = true;
        rep(k, N) {
            if (i == k) continue;
            if (s[i][0] == s[k][0] || s[i][0] == s[k][1]) ok1 = false;
            if (s[i][1] == s[k][0] || s[i][1] == s[k][1]) ok2 = false;
        }
        if (ok1 == false && ok2 == false) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
