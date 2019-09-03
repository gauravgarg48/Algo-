#include<bits/stdc++.h>
using namespace std;
int main() {
    int i, j, n, x, sum;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> x;
    sort(arr, arr+n);
    i = 0;
    j = n-1;
    while(i < j) {
        sum = arr[i]+arr[j];
        if(x == sum) {
            cout << arr[i] << " and " << arr[j] << endl;
            i++;
            j--;
        }
        else if(x < sum)
            j--;
        else
            i++;
    }
	return 0;
}