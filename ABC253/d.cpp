#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      包除原理
      N以下でAの倍数でもBの倍数でもないものの総和 ＝ N以下の総和ーN以下のAの倍数の総和 ー N以下のBの倍数の総和 ＋ N以下のAの倍数かつBの倍数であるものの総和
      N以下のAの倍数の総和はA*(1+2+...+N/A)で計算可能。
    */
    int n, a, b;
    cin >> n >> a >> b;
    auto Sum = [&](ll x) { return x * (x + 1) / 2; };
    ll c = 1LL * a * b / __gcd(a, b);
    cout << Sum(n) - Sum(n / a) * a - Sum(n / b) * b + Sum(n / c) * c << endl;
}
