#include<iostream>
#include<string>
using namespace std;

string longestPalindrome(string s) {
	int i, j, k, maxi = 0, maxj = 0, n = s.length();
	for(k = 1; k < n; ++k) {
		i = j = k;
		while(i > 0 && j < n-1 && s[i-1] == s[j+1]) {
			i--;
			j++;
		}
		if(j-i > maxj-maxi) {
			maxi = i;
			maxj = j;
		}
		i = k;
		j = k-1;
		while(i > 0 && j < n-1 && s[i-1] == s[j+1]) {
			i--;
			j++;
		}
		if(j-i > maxj-maxi) {
			maxi = i;
			maxj = j;
		}
		cout << maxi << " " << maxj << endl;
	}
	
	return s.substr(maxi, maxj+1);
}

int main() { 
	string s;
	cin >> s;
	cout << longestPalindrome(s);
	return 0;
}