#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main() {
    int V, A, B, C;
    cin >> V >> A >> B >> C;
    while (true) {
        if ((V -= A) < 0) {
            cout << 'F' << endl;
            return 0;
        }
        if ((V -= B) < 0) {
            cout << 'M' << endl;
            return 0;
        }
        if ((V -= C) < 0) {
            cout << 'T' << endl;
            return 0;
        }
    }
}
