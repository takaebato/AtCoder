#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = j; i < (int)(n); i++)

ll calcX(int a, int b) {
    return pow(a, 3) + pow(a, 2) * b + a * pow(b, 2) + pow(b, 3);
}

int main() {
    ll N;
    cin >> N;
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    int range = pow(10, 6);
    ll minX = powl(10, 18);
    int index, left, right;
    rep(i, range) {
        left = i;
        right = range;
        while (right - left > 1) {
            index = left + (right - left) / 2;
            if (calcX(i, index) >= N) {
                right = index;
            } else {
                left = index;
            };
        }

        minX = min(minX, calcX(i, right));
    }
    cout << minX << endl;
}
