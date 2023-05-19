#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = j; i < (int)(n); i++)

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N, 0);
    vector<int> b(M, 0);
    rep(i, N) cin >> a[i];
    rep(i, M) cin >> b[i];
    rep(i, M) {
        rep(k, N) {
            if (b[i] == a[k]) {
                a[k] = 0;
                break;
            }

            if (k == N - 1) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
