#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      「条件を満たすものを構築して出力せよ」 -> 構築/構成 (constructive problem) というらしい。そして、閃きを要求するらしい。
      今回のはN進数を上手く使う問題だった。
      一般に、1桁以上d桁以下のp進表記を用いると、p^d−1以下のすべての非負整数を表現することができる。
      ex)
      2進数3つは6個で7まで表現できる
      3進数3つは9個で26まで表現できる
      10進数3つは30個で999まで表現できる
      16進数3つは48個で4095まで表現できる
      100進数3つは300個で99999まで表現できる
    */
    int W;
    cin >> W;
    cout << "297" << endl;
    repg(i, 1, 100) {
        cout << i << " ";
        cout << i * 100 << " ";
        cout << i * 10000 << (i == 99 ? "\n" : " ");
    }
}
