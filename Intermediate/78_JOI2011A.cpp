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
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

/*
  クエリ問題。2次元区間に含まれる3種類の文字の個数を計算する。
  愚直だと0(KMN)=10^11
  クエリは取得のみで、更新などは含まれないため、累積和でいける。
*/
int main() {
    int M, N, K;
    cin >> M >> N >> K;
    vec<string> m(M);
    rep(i, M) cin >> m[i];
    vvec<int> cumj(M + 1, vec<int>(N + 1, 0));
    vvec<int> cumo(M + 1, vec<int>(N + 1, 0));
    vvec<int> cumi(M + 1, vec<int>(N + 1, 0));
    rep(i, M) rep(k, N) {
        switch (m[i][k]) {
            case 'J':
                cumj[i + 1][k + 1]++;
                break;
            case 'O':
                cumo[i + 1][k + 1]++;
                break;
            case 'I':
                cumi[i + 1][k + 1]++;
                break;
        }
        cumj[i + 1][k + 1] += cumj[i + 1][k] + cumj[i][k + 1] - cumj[i][k];
        cumo[i + 1][k + 1] += cumo[i + 1][k] + cumo[i][k + 1] - cumo[i][k];
        cumi[i + 1][k + 1] += cumi[i + 1][k] + cumi[i][k + 1] - cumi[i][k];
    }
    rep(qi, K) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int j, o, i;
        j = cumj[c][d] - cumj[c][b - 1] - cumj[a - 1][d] + cumj[a - 1][b - 1];
        o = cumo[c][d] - cumo[c][b - 1] - cumo[a - 1][d] + cumo[a - 1][b - 1];
        i = cumi[c][d] - cumi[c][b - 1] - cumi[a - 1][d] + cumi[a - 1][b - 1];
        printf("%d %d %d\n", j, o, i);
    }
}

int main() {
    int M, N, Q;
    cin >> M >> N >> Q;
    vec<string> a(M);
    rep(i, M) cin >> a[i];

    vvec<int> cum(M + 1, vec<int>(N + 1, 0));
    rep(i, M) rep(j, N) cum[i + 1][j + 1] = cum[i + 1][j] + cum[i][j + 1] - cum[i][j] + a[i][j];

    rep(qi, Q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << cum[c][d] - cum[c][b - 1] - cum[a - 1][d] + cum[a - 1][b - 1] << endl;
    }
}
