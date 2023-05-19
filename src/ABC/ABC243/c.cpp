#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<vector<int>> p(N, vector<int>(3));
    rep(i, N) { cin >> p[i][0] >> p[i][1]; }
    string S;
    cin >> S;
    int i = 0;
    for (char& c : s) {
        if (c == 'R') {
            p[i][2] = 0;
            i++;
        } else if (c == 'L') {
            p[i][2] = 1;
            i++;
        }
    }

}
