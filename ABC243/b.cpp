#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    int sum1 = 0;
    rep(i, N) if (A[i] == B[i]) sum1++;

    int sum2 = 0;
    sort(B.begin(), B.end());
    rep(i, N) if (binary_search(B.begin(), B.end(), A[i])) sum2++;

    cout << sum1 << endl;
    cout << sum2 - sum1 << endl;
}
