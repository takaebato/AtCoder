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

/*
  数学的問題のかなり簡単なもの。
  10^12だから探索は無理。数学的に考察して計算で求めるパターン。
*/
int main() {
    ll A, B, K;
    cin >> A >> B >> K;
    if (A >= K) {
        A -= K;
        printf("%lld %lld\n", A, B);
    } else {
        B = max(0LL, B - (K - A));
        A = 0;
        printf("%lld %lld\n", A, B);
    }
}
