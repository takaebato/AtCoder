#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main() {
    char s1, s2, s3;
    char t1, t2, t3;
    cin >> s1 >> s2 >> s3;
    cin >> t1 >> t2 >> t3;

    int diff = 0;
    if (s1 != t1) {
        diff++;
    }
    if (s2 != t2) {
        diff++;
    }
    if (s3 != t3) {
        diff++;
    }

    if (diff == 2) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

// 偶置換と奇置換の2グループに分けられる
#include <iostream>
#include <string>
using namespace std;
bool sign(string S){
    return S == "R G B" || S == "G B R" || S == "B R G";
}
int main(){
    string S, T;
    getline(cin, S);
    getline(cin, T);
    if(sign(S) == sign(T)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
