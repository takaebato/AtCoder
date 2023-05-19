#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      P<=10^18,
      初期速度V, 速度v, 合計時間t, 計算量P*V -> t=x+P*V/v -> f(x)=x+P*2^(-x/1.5)
      求めたいのはf(x)の最小値. 凸関数の極値とも言える.
        二分法はg(x)=0を求める手法だから、凸関数であるf(x)を微分すると単調性からdf(x)=0を二分法で求めて答えは導ける。
        また、最小値は三分法によって直接求めることもできる。
      要は解法は三つ
      1. 微分して二分法
      2. 三分探索
      3. 黄金分割探索
    */

    // 1. 微分して二分法。探索範囲は[0,P]で十分。
    //    計算量はP/2^xが10^-8未満くらいになるまでループ回せばOK. だから、O(log(P*10^8))くらい。多めに見積もってO(log(10^30))くらいか. 100くらいかな。
    // というかdfの計算式がいつの間にかintで切り捨てになってしまってた。 double計算になるように、.0つけたり、キャストしたりをこまめにした方が吉。
    double P;
    cin >> P;
    auto f = [P](double x) { return x + P / pow(2, x / 1.5); };
    auto df = [P](double x) { return 1.0 - (2.0 / 3) * log(2.0) * P / pow(2, x / 1.5); };
    double lo = 0, hi = 1e20;
    rep(i, 200) {
        double mi = lo + (hi - lo) / 2;
        if (df(mi) < 0)
            lo = mi;
        else
            hi = mi;
    }
    cout << fixed << setprecision(10) << f(lo) << endl;

    // 2. 三分探索
    // double P;
    // cin >> P;
    // auto f = [=](double x) { return x + P / pow(2, x / 1.5); };
    // double lo = 0, hi = 1e20;
    // rep(i, 200) {
    //     double c1 = (lo * 2 + hi) / 3;
    //     double c2 = (lo + hi * 2) / 3;
    //     if (f(c1) > f(c2))
    //         lo = c1;
    //     else
    //         hi = c2;
    // }
    // cout << fixed << setprecision(10) << f(lo) << endl;

    // 3. 黄金分割探索
    // double P;
    // cin >> P;
    // auto f = [=](double x) { return x + P / pow(2, x / 1.5); };
    // const double GR = (sqrt(5) - 1.0) / 2.0;  // Golden Rule == 0.618
    // double lo = 0, hi = 1e20;
    // rep(i, 200) {
    //     double c1 = hi - GR * (hi - lo);
    //     double c2 = lo + GR * (hi - lo);
    //     if (f(c1) > f(c2))
    //         lo = c1;
    //     else
    //         hi = c2;
    // }
    // cout << fixed << setprecision(10) << f(lo) << endl;
}
