#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = j; i < (int)(n); i++)

int main() {
    vector<vector<int>> p(4, vector<int>(2));
    rep(i, 3) cin >> p[i][0] >> p[i][1];
    int x = 0;
    int y = 0;
    if (p[0][0] == p[1][0]) {
        x = p[2][0];
    } else if (p[0][0] == p[2][0]) {
        x = p[1][0];
    } else {
        x = p[0][0];
    }
    if (p[0][1] == p[1][1]) {
        y = p[2][1];
    } else if (p[0][1] == p[2][1]) {
        y = p[1][1];
    } else {
        y = p[0][1];
    }
    cout << x << " " << y << endl;
}
