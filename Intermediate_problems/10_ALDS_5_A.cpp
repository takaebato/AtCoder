#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    // n<=20, q<=200, Ai,mi<=2*10^3.
    // いくつかの要素を選ぶ → 選ぶ数が決まっていないため、全ての要素に対して選ぶor選ばないで2^n通りある
    // 200個のクエリに回答するため、2^20*200で大体10^8とかになる. ギリいけそうだがという感じ.
    // クエリ回答系のセオリーとして答えをキャッシュしておくのがあるから、今回も2^20=10^6程度のメモリ消費してキャッシュする.
    // 定数倍でアクセスできればいいから、配列でもsetでも可
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    int q;
    cin >> q;
    vector<int> query(q);
    rep(i, q) cin >> query[i];

    set<int> s;
    for (int i = 0; i < (1 << N); i++) {
        int sum = 0;
        rep(l, N) if (i & (1 << l)) sum += a[l];
        s.insert(sum);
    }

    rep(i, q) {
        if (s.find(query[i]) != s.end()) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}
