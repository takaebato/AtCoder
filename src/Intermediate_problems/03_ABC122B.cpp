#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    // S<=10. 答えとしてあり得る部分文字列は全部でN^2.各探索でN. O(N^3)なので単純な全探索で余裕で間に合う.
    string s;
    cin >> s;
    int maxLen = 0;
    string agct = "AGCT";
    rep(i, s.size()) {
        repg(k, i, s.size()) {
            string str = "";
            bool ok = true;
            repg(l, i, k + 1) {
                if (agct.find(s[l]) != string::npos) {
                    str += s[l];
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok)
                if (maxLen < str.size()) maxLen = str.size();
        }
    }
    cout << maxLen << endl;
}
