#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      クエリ問題。N,Q<=10^5だから、Q個のクエリに対して線形Nだと間に合わない。
      だから前処理とかデータ構造とかを上手く使って、毎クエリの計算量をlogNとか1とかにしたい気持ちになる。

      1. 先頭からの数に応じた集合の要素比較。iの増加で要素数も広義単調増加する。要素数がそれぞれの区間になって、要素数と要素の一致性が一対一対応しそうだという考察が浮かぶ。
      要素数と一致性が対応することから、anum[i]=要素数、bnum[i]=要素数、match[要素数]＝一致性bool、的なデータ構造で持たせておけば、O(1)で処理できる。
      二つの集合の要素が等しいかどうかの比較だから、要はXORを要素数ごとに見ていることでもあるか。
      実装的には、尺取の要領でのインデックス操作がだいぶ難しい。

      2. ハッシュを使う方法。
      a,bの各インデックスごとの集合を保持しようとすると、最悪でN^2で収まらないし、それに収められても一致性比較で、結局Nかかる。setだと地味にNlogNかかる。
      これを、各部分集合をハッシュに割り当てることで、Nで収めるというアイデア。
    */

    // 1. Nループに対して、setのinsert, eraseでlogN。各クエリは1でいけるから、計算量はO(NlogN + Q).
    int N, Q;
    cin >> N;
    vector<int> a(N), b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];

    vector<int> anum(N), bnum(N);
    unordered_set<int> aset, bset, sec;
    rep(i, N) {
        aset.insert(a[i]);
        bset.insert(b[i]);
        anum[i] = aset.size();
        bnum[i] = bset.size();
    }

    vector<int> mat(N, false);
    int ida = 0, idb = 0;
    while (ida < N && idb < N) {
        if (anum[ida] == bnum[idb]) {
            if (sec.find(a[ida]) == sec.end()) {
                sec.insert(a[ida]);
            } else {
                sec.erase(a[ida]);
            }
            if (sec.find(b[idb]) == sec.end()) {
                sec.insert(b[idb]);
            } else {
                sec.erase(b[idb]);
            }
            if (sec.empty()) mat[anum[ida]] = true;
            int tmpa = anum[ida], tmpb = bnum[idb];
            while (tmpa == anum[ida]) ida++;
            while (tmpb == bnum[idb]) idb++;
        } else if (anum[ida] < bnum[idb]) {
            ida++;
        } else if (anum[ida] > bnum[idb]) {
            idb++;
        }
    }

    cin >> Q;
    rep(i, Q) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (anum[x] == bnum[y] && mat[anum[x]])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
