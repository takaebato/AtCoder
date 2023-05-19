#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

struct Point {
    ll px, py;
};

Point operator+(const Point& a1, const Point& a2) { return Point{a1.px + a2.px, a1.py + a2.py}; }

Point operator-(const Point& a1, const Point& a2) { return Point{a1.px - a2.px, a1.py - a2.py}; }

bool operator<(const Point& a1, const Point& a2) {
    if (a1.px < a2.px) return true;
    if (a1.px > a2.px) return false;
    if (a1.py < a2.py) return true;
    return false;
}

ll cp(Point p1, Point p2) { return p1.px * p2.py - p1.py * p2.px; }

int main() {
    /*
      N<=10^5, Xi,Yi<=4*10^8 （蛇足だが切り分けるのは一回だけ。そして正N角形ではない。スマホで読んでたらダブルで勘違いした。）
      これも探索問題か. 愚直な切り分け方はN^2通り. 判定は、単純に凸角形の面積を求めるのは高々(N-2)個三角形を足す必要があるため、O(N).  ただ、毎回面積を保持していれば三角形を足せばいいのでO(1)には簡単にできる。
      答えとしてあり得る：面積の状態としては全組み合わせあり得るから絞れないか.
      一部決定で残り決まる：一つの頂点を決めると、残りは各組合せの面積さえわかっていれば、S/4の二分探索ができるが、今回はその各組み合わせの面積は10^10通りあってキャッシュできない、というか計算できない.
      各頂点移動と面積に単調増加の関係があるから二分探索自体はできるが、その判定のための面積の計算にNかかって本末転倒。
      -> 凸性から、点の移動による単調増加性や単調減少性が見てとれるから、尺取的なやり方が思い浮かぶ.
      -> そしてこれが実際にすごく上手く行く. 図を書いて試すと尺取の正当性がわかる.
    */
    int N;
    cin >> N;
    vector<Point> pts(N);
    rep(i, N) cin >> pts[i].px >> pts[i].py;

    ll s = 0;
    repg(i, 2, N) s += abs(cp(pts[i - 1] - pts[0], pts[i] - pts[0]));
    ll res = LLONG_MAX, e = 0;
    int q = 1;
    rep(p, N) {
        while (4 * e < s) {
            e += abs(cp(pts[q] - pts[p], pts[(q + 1) % N] - pts[p]));
            q++, q %= N;
            res = min(res, abs(4 * e - s));
        }
        e -= abs(cp(pts[p] - pts[q], pts[(p + 1) % N] - pts[q]));
        res = min(res, abs(4 * e - s));
    }
    cout << res << endl;
}
