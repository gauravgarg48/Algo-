#include <bits/stdc++.h> 
using namespace std;
int knapsackNRec(int wt[], int cost[], int n, int k) {
	if(n < 0 || k <= 0)
		return 0;
	int x1, x2, c;
	x1 = x2 = c = 0;
	if(wt[n] < k) {
		c = k/wt[n];
		x1 = c*cost[n] + knapsackNRec(wt, cost, n-1, k-c*wt[n]);
	}
	x2 = knapsackNRec(wt, cost, n-1, k);
	return max(x1, x2);
}

int main() {
	int i, k, n;
	cin >> n >> k;
	int cost[n], wt[n];
	for(i = 0; i < n; ++i)
		cin >> wt[i];
	for(i = 0; i < n; ++i)
		cin >> cost[i];
	cout << knapsackNRec(wt, cost, n-1, k);
	return 0;
}