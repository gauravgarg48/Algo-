#include<iostream>
#include<vector>
using namespace std;

int BinSearchRec(vector<int> a, int beg, int end, int x) {
	if(beg > end)
		return -1;
	int mid = (beg+end)/2;
	if (a[mid] == x)
		return mid;
	else if (a[mid] < x)
		return BinSearchRec(a, mid+1, end, x);
	else
		return BinSearchRec(a, beg, mid-1, x);
}

int main() {
	int n, x, i;
	cin >> n;
	vector<int> v;
	for(i = 0; i < n; ++i) {
		cin >> x;
		v.push_back(x);
	}
	cin >> x;
	cout << BinSearchRec(v, 0, n-1, x);
	return 0;
}