#include<iostream>
using namespace std;
const int MAX = 30;

void print_array(int arr[], int n) {
    for(int j = 0; j < n; ++j)
            cout << arr[j] << ' ';
}

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for(i = 1; i < n; ++i) {
        j = i-1;
        key = arr[i];
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge(int arr[], int beg, int mid, int end) {
    int new_arr[end-beg+1], i = beg, j = mid+1, k = 0;
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            new_arr[k] = arr[i];
            i++;
            k++;
        }
        else {
            new_arr[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= mid) {
        new_arr[k] = arr[i];
        i++;
        k++;
    }
    while(j <= end) {
        new_arr[k] = arr[j];
        j++;
        k++;
    }

    for(i = beg; i <= end; ++i)
        arr[i] = new_arr[i-beg];
}

void merge_sort(int arr[], int beg, int end) {
    if(beg < end) {
        int mid = (beg+end)/2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, beg, mid, end);
    }
}

int partition(int arr[], int beg, int end) {
    int i, tmp, p = beg;
    for(i = beg; i < end; ++i) {
        if(arr[i] < arr[end]) {
            tmp = arr[i];
            arr[i] = arr[p];
            arr[p] = tmp;
            p++;
        }
    }
    tmp = arr[p];
    arr[p] = arr[end];
    arr[end] = tmp;
    return p;
}

int quick_sort(int arr[], int beg, int end) {
    if(beg < end) {
        int pindex = partition(arr, beg, end);
        quick_sort(arr, beg, pindex-1);
        quick_sort(arr, pindex+1, end);
    }
    return 0;
}

int main() {
	int arr[MAX], n, i;
	cout << "n: ";
    cin >> n;
	cout << "arr: ";
	for(i = 0; i < n; ++i)
		cin >> arr[i];
    quick_sort(arr, 0, n-1);
    print_array(arr, n);
}