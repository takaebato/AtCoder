#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> v;
	int i = 0;
	while(N != 0){
		v[i] = N % 10;
		N /= 10;
		i++;
	}
	cout << v[5] << endl;
}
