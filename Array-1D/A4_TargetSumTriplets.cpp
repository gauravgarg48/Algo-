#include<bits/stdc++.h>
using namespace std;
int main() {
    int i, j, k, n, x, t, sum;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> t;
    sort(arr, arr+n);
    for(k = 0; k < n; ++k) {
        x = t-arr[k];
        i = k+1;
        j = n-1;
        while(i < j) {
            sum = arr[i]+arr[j];
            if(x == sum) {
                cout << arr[k] << ", " << arr[i]
                    << " and " << arr[j] << endl;
                i++;
                j--;
            }
            else if(x < sum)
                j--;
            else
                i++;
        }
    }
	return 0;
}