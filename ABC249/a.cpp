#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;
    int distT = 0;
    int distA = 0;
    repg(i, 1, X + 1) {
        if (1 <= i % (A + C) && i % (A + C) <= A) {
            distT += B;
        }
        if (1 <= i % (D + F) && i % (D + F) <= D) {
            distA += E;
        }
    }
    if (distT == distA) {
        cout << "Draw" << endl;
    } else if (distT > distA) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}
