#include<iostream>
#include<cstdlib>
using namespace std;

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int* a, int beg, int end) {
	int i, p, j = beg;
	p = beg + rand() % (end-beg+1);
    swap(&a[p], &a[end]);
    p = end;
    for(i = beg; i < end; ++i) {
    	if(a[i] < a[p]) {
    		swap(&a[i], &a[j]);
    		j++;
    	}
    }
    swap(&a[j], &a[p]);
	return j;
}

void quickSort(int* a, int beg, int end) {
	if(beg < end) {
		int pivot = partition(a, beg, end);
		quickSort(a, beg, pivot-1);
		quickSort(a, pivot+1, end);
	}
}

int main() {
	int n, i;
	cin >> n;
	int a[200000];
	for(i = 0; i < n; ++i)
		cin >> a[i];
	quickSort(a, 0, n-1);
	for(i = 0; i < n; ++i)
		cout << a[i] << " ";
	return 0;
}