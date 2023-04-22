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
  N<=10^9だから線形は無理。二分探索などでもなさそうだから数学的考察で特殊な解き方がありそうだとなる。
  各iについて、最善解は、0+1+..+N-1であるが、実際にそう出来る選び方があるのでそれが答えになる。
*/
int main() {
    int N;
    cin >> N;
    cout << 1LL * N * (N - 1) / 2 << endl;
}
