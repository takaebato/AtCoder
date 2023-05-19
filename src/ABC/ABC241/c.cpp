#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = j; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<string> s(N);
    rep(i, N) cin >> s[i];
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    rep(i, N) {
        rep(k, N) {
            rep(l, 6) {
                if (i + l > N - 1) {
                    a = 0;
                    break;
                }
                if (s[i + l][k] == '#') a++;
            }
            rep(l, 6) {
                if (k + l > N - 1) {
                    b = 0;
                    break;
                }
                if (s[i][k + l] == '#') b++;
            }
            rep(l, 6) {
                if (i + l > N - 1 || k + l > N - 1) {
                    c = 0;
                    break;
                }
                if (s[i + l][k + l] == '#') c++;
            }
            rep(l, 6) {
                if (i + l > N - 1 || k - l < 0) {
                    d = 0;
                    break;
                }
                if (s[i + l][k - l] == '#') d++;
            }
            if (a >= 4 || b >= 4 || c >= 4 || d >= 4) {
                cout << "Yes" << endl;
                return 0;
            }
            a = 0;
            b = 0;
            c = 0;
            d = 0;
        }
    }
    cout << "No" << endl;
}
