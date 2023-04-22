#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
template <class T, class U>
using P = pair<T, U>;
#define pb push_back
#define eb emplace_back
#define em emplace
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n + 1); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int h1, h2, h3, w1, w2, w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    int ans = 0;
    for (int a = 1; a < max(h1, w1); a++) {
        for (int b = 1; b < max(h1, w2); b++) {
            for (int e = 1; e < max(h2, w2); e++) {
                for (int j = 1; j < max(h3, w3); j++) {
                    int c = h1 - a - b;
                    int f = w3 - c - j;
                    int d = h2 - e - f;
                    int h = w1 - a - d;
                    int i = h3 - h - j;
                    if (!(c < 1 || f < 1 || d < 1 || h < 1 || i < 1))
                        if (w2 == b + e + i) ans++;
                }
            }
        }
    }
    cout << ans << endl;
}
