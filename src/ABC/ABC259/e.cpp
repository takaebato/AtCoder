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

/*
  愚直に行くとどうなるか？
  各aiの計算でlog(e11)+log(e12)+...+log(e1m), これがN個ある。
  aiが求まった後は、1にする数を選び、最小公倍数の計算でNlog(max(ai))程度。
  よって、O((log(e11)+log(e12)+...+log(e1m)) + ... +(log(eN1)+log(eN2)+...+log(eNm)) + N^2log(max(ai)))
  最悪で、O(10^5*log(10^9) + 10^10*log(10^5))とかだろうか。
*/
int main() {}
