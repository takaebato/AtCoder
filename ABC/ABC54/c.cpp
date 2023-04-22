#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)


int def(int v, int N,vector<bool>& visited){

}

// 隣接行列
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> graph(N, vector<bool>(N));
    rep(i, N) {
        int A, B;
        cin >> A >> B;
        graph[A - 1][B - 1] = graph[B - 1][A - 1] = true;
    }

    vector<bool> visited(N,false);
    visited[0]=true;
    cout<<dfs(0,N,visited)<< endl;
}

// 隣接リスト

