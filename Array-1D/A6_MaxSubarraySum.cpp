#include<iostream>
using namespace std;
// Kadane's Algorithm
int main() {
    int t, n, i, csum, msum;
    cin >> t;
    while(t--) {
        cin >> n;
        int arr[n];
        csum = msum = 0;
        for(i = 0; i < n; ++i) {
            cin >> arr[i];
            csum += arr[i];
            if(csum < 0)
                csum = 0;
            if(csum > msum)
                msum = csum;
                
        }
        cout << msum << endl;
    }
    return 0;
}