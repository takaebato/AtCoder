#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int sum = 0;

void QuickSort(vector<int>& l, int begin, int end){
	if(begin < 0 || begin >= l.size() || end < 0 || end >= l.size() || begin >= end){
		return;
	}
	sum += end - begin;
	int pivot = 0;
	int median = (end + begin)/2;
	vector<int> three = {l[begin], l[median], l[end]};
	sort(three.begin(), three.end());
	if(l[median] == three[1]){
		pivot = median;
	}else if(l[begin] == three[1]){
		pivot = begin;
	}else{
		pivot = end;
	}

	// for (int i = begin; i <= end; ++i){
	// 	if (l[i] == pivot){
	// 		swap(l[begin], l[i]);
	// 		break;
	// 	}
	// }
	// int pivot = end;
	swap(l[begin], l[pivot]);
	int p = l[begint];
	int c = begin;
	for (int i = begin; i <= end; ++i){
		if (l[i] <= p){
			swap(l[i], l[c]);
			c++;
		}
	}
	int index = c - 1;
	for (int i = begin; i <= end; ++i){
		if (l[i] == p){
			swap(l[index], l[i]);
			// break;
		}
	}
	// swap(l[begin], l[index]);

	int left = index - 1;
	int right = index + 1;

	QuickSort(l, begin, left);
	QuickSort(l, right, end);
}

int main(){
	vector<int> l(10000);
	for(int i = 0; i < 10000; ++i){
		cin >> l[i];
	}
	QuickSort(l, 0, l.size() - 1);
	cout << sum << endl;
}
