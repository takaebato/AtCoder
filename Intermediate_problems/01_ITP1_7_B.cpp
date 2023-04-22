#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    // 答えとしてあり得る組合せの数はnC3. n<=10^2 だから3重ループでも十分いける.
    int n, x;
    do {
        cin >> n >> x;
        if (n == 0 && x == 0) return 0;

        int count = 0;
        repg(i, 1, n + 1) {
            repg(k, i + 1, n + 1) {
                repg(l, k + 1, n + 1) {
                    if (i + k + l == x) count++;
                }
            }
        }
        cout << count << endl;
    } while (true);
}
