#include<iostream>
#include<vector>
using namespace std;

int countPoints(int arr[][5], int i, int j, int r) {
	if(i == -1)
		return 0;

	int max, p, v = arr[i][j];
	if (r <= j < r+5 && v == -1)
		v = 0;
	max = countPoints(arr, i-1, j, r) + v;
	if(j > 0) {
		p = countPoints(arr, i-1, j-1, r) + v;
		if(max < p)
			max = p;
	}
	if(j < 4) {
		p = countPoints(arr, i-1, j+1, r) + v;
		if(max < p)
			max = p;
	}
	return max;
}

int main() {
	int arr[15][5], t, i, h, j, x, max;
	cin >> t;
	while(t-- > 0) {
		cin >> h;
		for(i = 0; i < h; ++i)
			for(j = 0; j < 5; ++j)
				cin >> arr[i][j];
		max = countPoints(arr, h, 2, 0);
		cout << max << endl;
	}
	for(i = 0; i < h-4; ++i) {
			x = countPoints(arr, h, 2, i);
			cout  << x <<endl;
			if(x > max)
				max = x;
		}
	return 0;
}