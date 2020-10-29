#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main() {
    int n, in, out = 0;
    cin >> n;
    vector<int> a(2 * n + 2, false);
    a[0] = true;

    while (true) {
        rep(i, a.size()) {
            if (a[i] == false) {
                out = i;
                a[i] = true;
                break;
            }
        }
        cout << out << flush;
        cin >> in;
        if (in == 0) {
            break;
        }
        a[in] = true;
    }
}
