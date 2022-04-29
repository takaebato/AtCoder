#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    ll A, B, K;
    cin >> A >> B >> K;
    int count = 0;
    while (true) {
        if (A < B) {
            count++;
            A *= K;
        } else {
            cout << count << endl;
            return 0;
        }
    }
}
