#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int M = 2 * pow(10, 5) + 10;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    vector<int> num(M, 0);
    int sum = 0;
    rep(i, N) { num[a[i]]++; }
    rep(i, N) {
        repg(k, 1, sqrt(a[i]) + 1) {
            if (a[i] % k == 0) {
                if (k == 1) {
                    if (num[k] == 0 || num[a[i] / k] == 1) continue;

                }
            } else if (k != a[i] / k) {
                sum += num[k] * num[a[i] / k] * 2;
            } else {
            }
        }
    }
}
cout << sum << endl;
}
