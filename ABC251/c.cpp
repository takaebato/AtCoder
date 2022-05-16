#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      これも計算量考えて、素直に線形探索してsetとか使って重複消して、もう一回線形探索して行ける問題だった。
    */
    int N;
    cin >> N;
    vector<pair<string, int>> vec(N);
    rep(i, N) cin >> vec[i].first >> vec[i].second;
    set<string> s;
    rep(i, N) {
        if (s.find(vec[i].first) == s.end())
            s.insert(vec[i].first);
        else
            vec[i].second = -1;
    }
    int val = -1;
    int idx = -1;
    rep(i, N) {
        if (val < vec[i].second) {
            val = vec[i].second;
            idx = i + 1;
        }
    }
    cout << idx << endl;
}
