#include <bits/stdc++.h> 
using namespace std; 

int LCS3count(string s1, string s2, string s3) {
    int i, j, k;
    int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
    vector<vector<vector<int>>> dp;
    for(i = 0; i <= n1; ++i) {
        vector<vector<int>> arr;
        for(j = 0; j <= n2; ++j) {
            vector<int> v(n3+1, 0);
            arr.push_back(v);
        }
        dp.push_back(arr);
    }
    for(i = 1; i <= n1; ++i) {
        for(j = 1; j <= n2; ++j) {
            for(k = 1; k <= n3; ++k) {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n1][n2];
}

int main() {
	string s1, s2;
	cin >> s1 >> s2 >> s3;
    cout << LCS3count(s1, s2, s3);
	return 0;
}