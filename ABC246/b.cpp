#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = j; i < (int)(n); i++)

int main() {
    double x, y, dist, ax, ay;
    cin >> x >> y;
    dist = sqrt(x * x + y * y);
    ax = x / dist;
    ay = y / dist;
    cout << fixed << setprecision(15) << ax << " " << ay << endl;
}
