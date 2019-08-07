#include<iostream>
using namespace std;
#define mod 1000000007

long tile(int n, int m) {
	long dp[n+1], i;
    for (i = 1; i <= n; i++) { 
        if (i > m) 
            dp[i] = dp[i - 1] + dp[i - m]; 
        else if (i < m) 
            dp[i] = 1; 
        else
            dp[i] = 2;
    }
	return dp[n]%mod;
}

int main(){
	int t, n, m;
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> n >> m;
		cout << tile(n, m) << endl;
	}
	return 0;
}