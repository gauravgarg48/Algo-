#include <bits/stdc++.h> 
using namespace std; 

int compute(vector<int>arr, int k) {
    int i, j, max, count, n = arr.size();
    int dp[n+1];
    dp[0] = 0;
    for(i = 1; i <= n; ++i) {
        if(arr[i] < 0&&i>=k)
            dp[i] = dp[i-k]+max(arr[i],0);
        else {
            if(arr[i] > dp[i-k] + arr[i])
                dp[i] = arr[i];
            else
                dp[i] = dp[i-k] + arr[i];
        }
    }
    return dp[n];
}

int main() {
	vector<int> arr;
    int c = -1;
    for(int i = 1; i <= 10; ++i) {
        arr.push_back(i*c);
        c *= -1;
        cout << arr[i-1] << " ";
    }
    cout << compute(arr, 1);
	return 0;
}