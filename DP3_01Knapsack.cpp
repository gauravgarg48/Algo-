#include <bits/stdc++.h> 
using namespace std;
int knapsackRec(int wt[], int cost[], int n, int k) {
	if(n < 0 || k < 0)
		return 0;
	int x1, x2;
	x1 = x2 = 0;
	if(wt[n] < k)
		x1 = cost[n] + knapsackRec(wt, cost, n-1, k-wt[n]);
	x2 = knapsackRec(wt, cost, n-1, k);
	return max(x1, x2);
}

int knapsack(int wt[], int cost[], int n, int k) {
	int dp[n+1][k+1];
	int i, j;
	for(i = 0; i <= n; ++i) {
		for(j = 0; j <= k; ++j) {
			if(i == 0 || n == 0)
				dp[i][j] = 0;
			else if(j >= wt[i-1])
				dp[i][j] = max(cost[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][k];
}

int main() {
	int i, k, n;
	cin >> n >> k;
	int cost[n], wt[n];
	for(i = 0; i < n; ++i)
		cin >> wt[i];
	for(i = 0; i < n; ++i)
		cin >> cost[i];
	cout << knapsack(wt, cost, n-1, k);
	return 0;
}