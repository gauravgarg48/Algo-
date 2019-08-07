#include<iostream>
#include<vector>
using namespace std;

vector<int> BSortRec(vector<int> a, int j, int n) {
	if(n == 1)
		return a;
	if(j == n-1)
		return BSortRec(a, 0, n-1);
	
	if (a[j] > a[j+1]) {
		int x = a[j+1];
		a[j+1]=a[j];
		a[j]=x;
	}
	return BSortRec(a, j+1, n);
}

int main() {
	int n, x, i;
	cin >> n;
	vector<int> v;
	for(i = 0; i < n; ++i) {
		cin >> x;
		v.push_back(x);
	}
	v = BSortRec(v, 0, n);
	for(i = 0; i < n; ++i)
		cout << v[i] << " ";
	return 0;
}