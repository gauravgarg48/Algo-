#include <bits/stdc++.h> 
using namespace std;
int knapsackRec(int w[], int c[], int n, int m, int x) {
	if(m == 0)
		return 0;
	else if(x == 0)
		return -1;

	int i, wt, ans = 0;
	for(i = 0; i < n; ++i)
		if(c[i] == m && w[i] <= x) {
			wt = w[i] + knapsackRec(w, c, n, m-1, x-w[i]);
			if(wt > ans)
				ans = wt;
		}
	return ans;
}

int knapsack(int w[], int c[], int n, int m, int x) {
	int dp[m][x+1];
	int i, j;
	for(i = 1; i <= m; ++i) {
		for(j = 0; j <= x; ++j) {
			
		}
	}
	return dp[m-1][x];
}

int main() {
	int i, n, m, x, res;
	cin >> n >> m >> x;
	int w[n], c[n];
	for(i = 0; i < n; ++i)
		cin >> w[i];
	for(i = 0; i < n; ++i)
		cin >> c[i];
	res = knapsackRec(w, c, n, m, x);
	if(res >= 0)
		res = x-res;
	cout << res;
	return 0;
}