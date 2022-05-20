#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

/*
  素数関連. エラトステネスの篩っぽいものはサッと実装できるのがいいかもしれない. 今回だと微妙に改変するともっとスッキリ実装できた.
  これは探索問題. N=10^18を愚直探索して判定していたら到底間に合わない.
  答えとしてあり得る：
    答えとしてはN全てがあり得るわけではなく、実際はp*q^3が取り得る値のみ.
    そして、素因数分解の一意性から、k=p*q^3で、kの個数は(p,q)の組の個数と同値. かつ、何よりq^3からあり得るqの範囲がq<=10^6.
    ただこのままの愚直探索だと、p,qそれぞれでループするから10^12かかる.
    ↓
  一部決定で他決定：
    pが決まれば、欲しい値はq^3に関して二分探索して境界値を見つければ、計算で求められる. 要はNlogNにできる.
    また、pを小さい方から調べると、q^3の境界値は（広義）単調減少することから、尺取っぽくNでもいける.
    ある値を探索していく時に、もう一つの値の判定結果の区間が（広義）単調減少や増加するケースだと、その境界値を二分探索してもいいし、境界値を尺取っぽく移動するのでもいける.
*/

// コンテスト時の解. 考え方はだいたい合っていたが実装はかなりゴリ押し. よくバグらなかったなと思うくらい.
// vector<bool> make_is_prime(int N) {
//     vector<bool> prime(N + 1, true);
//     if (N >= 0) prime[0] = false;
//     if (N >= 1) prime[1] = false;
//     for (int i = 2; i * i <= N; i++) {
//         if (!prime[i]) continue;
//         for (int j = i * i; j <= N; j += i) {
//             prime[j] = false;
//         }
//     }
//     return prime;
// }

// int main() {
//     ll N;
//     cin >> N;
//     vector<bool> pr(1000010);
//     pr = make_is_prime(pow(10, 6));
//     vector<int> prime;
//     rep(i, pr.size()) if (pr[i]) prime.push_back(i);
//     sort(prime.begin(), prime.end());
//     vector<ll> pr3;
//     rep(i, prime.size()) pr3.push_back(pow(prime[i], 3));
//     ll ans = 0;
//     rep(i, prime.size()) {
//         ll tmp = N / prime[i];
//         auto it = upper_bound(pr3.begin(), pr3.end(), tmp);
//         ans += max(0, (int)(it - pr3.begin() - i - 1));
//     }
//     cout << ans << endl;
// }

// 改良版
// 素数の数は累積和で保持しておいて、境界値を求めたら累積和の配列へアクセスしてO(1)で取得、を10^6以下の素数分繰り返す。
int main() {
    const int M = 1e6;
    vector<bool> isP(M + 1, true);
    vector<int> primes;
    isP[0] = isP[1] = false;
    repg(i, 2, M + 1) {
        if (!isP[i]) continue;
        primes.push_back(i);
        for (ll k = (ll)i * i; k <= M; k += i) isP[k] = false;
    }

    vector<int> s(M + 1);
    for (int p : primes) s[p] = 1;
    rep(i, M) s[i + 1] += s[i];

    ll n;
    cin >> n;
    ll ans = 0;
    for (int q : primes) {
        int r = min<ll>(n / q / q / q, q - 1);
        ans += s[r];
    }
    cout << ans << endl;
}
