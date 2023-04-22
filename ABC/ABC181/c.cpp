#include <bits/stdc++.h>
using ll = long long;
using namespace std;
string judge(int c[][2], int N)
{
	for(int i =0; i<N-2;++i)
	{
		for(int j = i+1; j<N-1;++j)
		{
			for(int k = j+1; k<N; ++k)
			{
				if ((c[j][0] - c[i][0]) == 0){
					if(c[k][0] == c[i][0]){
						return "Yes";
					}
				}else if((c[k][1] - c[i][1]) - (double)(c[j][1] - c[i][1])/(c[j][0] - c[i][0])*(c[k][0] - c[i][0]) == 0)
				return "Yes";
			}
		}
	}
	return "No";
}
int main()
{
	int N;
	cin >> N;
	int c[N][2];
	for(int i =0; i<N;++i)
	{
		cin >> c[i][0] >> c[i][1];
	}
	cout << judge(c, N) << endl;
}