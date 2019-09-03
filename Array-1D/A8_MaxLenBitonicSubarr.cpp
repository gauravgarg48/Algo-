#include<iostream>
using namespace std;

int bitonic1(int *arr, int  n) {
    int max = 0, i, j, turn, x;
    for(i = 0; i < n; ++i) {
        x = arr[i];
        turn = 1;
        for(j = i; j < n; ++j) {
            if(turn == 1) {
                if(arr[j] >= x)
                    x = arr[j];
                else
                    turn = 2;
            }
            if(turn == 2) {
                if(arr[j] <= x)
                    x = arr[j];
                else
                    break;
            }
        }
        if(max < j-i)
            max = j-i;
    }
    return max;
}

int bitonic(int *arr, int  n) {
    int max = 0, i;
    int inc[n], dec[n];
    inc[0] = dec[n-1] = 1;
    for(i = 1; i < n; ++i) {
        if(arr[i] >= arr[i-1])
            inc[i] = inc[i-1] + 1;
        else
            inc[i] = 1;
    }
    for(i = n-2; i >=0; --i) {
        if(arr[i] >= arr[i+1])
            dec[i] = dec[i+1] + 1;
        else
            dec[i] = 1;
    }
    for(i = 0; i < n; ++i) {
        if(max < inc[i]+dec[i]-1)
            max = inc[i]+dec[i]-1;
    }
    return max;
}
int main() {
    int t, n, i;
    cin >> t;
    while(t--) {
        cin >> n;
        int arr[n];
        for(i = 0; i < n; ++i)
            cin >> arr[i];
        cout << bitonic(arr, n) << endl;
    }
    return 0;
}