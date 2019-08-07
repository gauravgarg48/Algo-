#include<iostream>
#include<vector>
using namespace std;

void merge(int* a, int beg, int mid, int end) {
	int i = beg, j = mid+1, k = 0;
    int tmp[end-beg+1];
	while(i <= mid && j <= end) {
		if (a[i] <= a[j])
			tmp[k] = a[i++];
		else
			tmp[k] = a[j++];
		k++;
	}
	while(i <= mid)
		tmp[k++] = a[i++];
	while(j <= end)
		tmp[k++] = a[j++];
	for(i = beg; i <= end; ++i)
		a[i] = tmp[i-beg];
	return;
}

void mergeSort(int* a, int beg, int end) {
	if(beg < end) {
		int mid = (beg+end)/2;
		mergeSort(a, beg, mid);
		mergeSort(a, mid+1, end);
		merge(a, beg, mid, end);
	}
}

int main() {
	int n, i;
	cin >> n;
	int a[200000];
	for(i = 0; i < n; ++i)
		cin >> a[i];
	mergeSort(a, 0, n-1);
	for(i = 0; i < n; ++i)
		cout << a[i] << " ";
	return 0;
}