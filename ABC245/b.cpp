#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    sort(A.begin(), A.end());
    rep(i, 2002) {
        bool res = binary_search(A.begin(), A.end(), i);
        if (!res) {
            cout << i << endl;
            return 0;
        }
    }
}
