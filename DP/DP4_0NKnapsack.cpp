#include <bits/stdc++.h> 
using namespace std;
int knapsackNRec(int wt[], int cost[], int n, int k) {
	if(n < 0 || k <= 0)
		return 0;
	int i, x, c, max = 0;
	c = k/wt[n];
	for(i = 0; i <=c; ++i) {
		x = i*cost[n] + knapsackNRec(wt, cost, n-1, k-i*wt[n]);
		if(max < x)
			max = x;
	}
	return max;
}

int knapsackN(int wt[], int cost[], int n, int k) {
	int i, j, x = 0, memo[k+1];
	memset(memo, 0, (k+1)*sizeof(int));
	for(i = 0; i <= k; ++i)
		for(j = 0; j < n; ++j)
			if(wt[j] <= i) {
				x = cost[j] + memo[i-wt[j]];
				if(memo[i] < x)
					memo[i] = x;
			}
	return memo[k];
}

int main() {
	int i, k, n;
	cin >> n >> k;
	int cost[n], wt[n];
	for(i = 0; i < n; ++i)
		cin >> wt[i];
	for(i = 0; i < n; ++i)
		cin >> cost[i];
	cout << knapsackN(wt, cost, n-1, k);
	return 0;
}