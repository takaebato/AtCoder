#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int N, M;
    cin >> N >> M;
    repg(i, 0, N + 1) {
        int b = 4 * N - M - 2 * i;
        int c = M - 3 * N + i;
        if (0 <= b && b <= N && 0 <= c && c <= N) {
            cout << i << " " << b << " " << c << endl;
            return 0;
        }
    }
    cout << "-1 -1 -1" << endl;
}
