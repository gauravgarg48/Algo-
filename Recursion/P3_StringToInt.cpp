#include<iostream>
using namespace std;

int stringToInt(string s, int n) {
	if(n == 0) return 0;
	int x = s[n-1] - '0';
	return stringToInt(s, n-1)*10 + x;
}

int main() {
	string s;
	cin >> s;
	cout << stringToInt(s, s.length());
	return 0;
}