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

struct Point {
    int x, y;
    double r;
    Point(int x = 0, int y = 0, double r = 0.0) : x(x), y(y), r(r) {}
};
/*
  最小の最大化。
  ある最小半径以下は可能で、それ以上は不可能になるから、区間が分かれる。
  よって、答えとしてありうる範囲を二分探索し判定する方法でいける。
  愚直に全部円の半径としてあり得るケースを探索するのは無理。
*/
int main() {
    int N, M;
    cin >> N >> M;
    vec<Point> ps(N + M);
    rep(i, N) cin >> ps[i].x >> ps[i].y >> ps[i].r;
    repg(i, N, N + M) cin >> ps[i].x >> ps[i].y;

    if (M == 0) {
        double ans = 1000;
        rep(i, N) ans = min(ans, ps[i].r);
        cout << ans << endl;
        return 0;
    }

    auto pow2 = [](double x) { return x * x; };
    auto dist = [&](Point a, Point b) { return pow2(a.x - b.x) + pow2(a.y - b.y); };

    double left = 0;
    double right = 400;
    rep(itr, 200) {
        double mid = left + (right - left) / 2.0;
        bool ok = true;
        repg(i, N, N + M) ps[i].r = mid;
        rep(i, N + M) {
            repg(j, i + 1, N + M) {
                if (dist(ps[i], ps[j]) < pow2(ps[i].r + ps[j].r)) ok = false;
            }
        }
        if (ok)
            left = mid;
        else
            right = mid;
    }
    printf("%.10lf\n", right);
}
