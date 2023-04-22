#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      マス目：8*8=64.
      BF: クイーンの置き方の全通り. 64C8で、まあ大体64^8=2^48=10^15で超多い. 判定でざっくり8*4*8=2*10^2くらいか.
      答えとしてあり得る：配置の方法で全通りと同じだと思う
      一部決定で他が決まる：今回だと意外と一つ置くだけで=29マスとか消えて、決まりはしないが、残りの選択肢をほぼ半減させたりもできる. 解が一意に定まるということはもう最後の一つを置くときは1マスしか余っていないはず.
      意外と泥臭く削っていくとorderまで減らせるのかもしれない.
    */
}
