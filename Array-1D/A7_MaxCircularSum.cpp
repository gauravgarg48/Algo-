#include<iostream>
using namespace std;

int main() {
    int t, n, i, len, csum, msum;
    cin >> t;
    while(t--) {
        cin >> n;
        int arr[2*n];
        csum = msum = len = 0;
        for(i = 0; i < n; ++i)
            cin >> arr[i];
        for(; i < 2*n; ++i)
            arr[i] = arr[n-i];
        
        for(i = 0; i < n; ++i) {
            csum += arr[i];
            len++;
            if(csum < 0) {
                csum = 0;
                len = 0;
            }
            if(csum > msum && len < n)
                msum = csum;
        }
        cout << msum << endl;
    }
    return 0;
}