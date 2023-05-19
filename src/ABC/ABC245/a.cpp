#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A < C) {
        cout << "Takahashi" << endl;
        return 0;
    } else if (A > C) {
        cout << "Aoki" << endl;
        return 0;
    } else if (A == C) {
        if (B < D) {
            cout << "Takahashi" << endl;
            return 0;
        } else if (B > D) {
            cout << "Aoki" << endl;
            return 0;
        } else if (B == D) {
            cout << "Takahashi" << endl;
            return 0;
        }
    }
}
