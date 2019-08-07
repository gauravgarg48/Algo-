#include <bits/stdc++.h> 
using namespace std; 

int profit[100];
int maxProfit(int price[], int n) {
    if(n == 0) return 0;
    if(profit[n] != -1)
        return profit[n];

    int best = 0, netProfit;
    for(int i = 1; i <= n; ++i) {
        netProfit = price[i] + maxProfit(price, n-i);
        best = max(best, netProfit);
    }
    profit[n] = best;
    return best;
}

int maxProfit_bu(int price[], int n) {
    int dp[100] = {};
    int len, cut;
    for(len = 1; len <= n; ++len) {
        int best = 0;
        for(cut = 1; cut <= len; ++cut)
            best = max(best, price[cut] + dp[len-cut]);
        dp[len] = best;
    }
    
    return dp[n];
}

int main() {
    int price[100];
    int n;
    cin >> n;
    profit[0] = -1;
	for(int i = 1; i <= n; ++i) {
        cin >> price[i];
        profit[i] = -1;
    }
    int ans = maxProfit(price, n);
    cout << ans;
	return 0;
}