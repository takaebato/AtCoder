#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

bool judge(int x, int y, int prev_x, int prev_y, int next_x, int next_y) {
    int p_x = prev_x - x;
    int p_y = prev_y - y;
    int n_x = next_x - x;
    int n_y = next_y - y;
    double p_th = atan2(p_y, p_x);
    double n_th = atan2(n_y, n_x);
    if (p_th <= 0) p_th += 2 * M_PI;
    if (n_th <= 0) n_th += 2 * M_PI;
    if (p_th < n_th) n_th -= 2 * M_PI;
    if (abs(p_th - n_th) > M_PI) return true;
    return false;
}

int main() {
    int ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    bool ok = true;
    if (judge(ax, ay, dx, dy, bx, by)) ok = false;
    if (judge(bx, by, ax, ay, cx, cy)) ok = false;
    if (judge(cx, cy, bx, by, dx, dy)) ok = false;
    if (judge(dx, dy, cx, cy, ax, ay)) ok = false;
    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
