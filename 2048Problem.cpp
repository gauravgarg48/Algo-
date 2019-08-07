#include<iostream>
using namespace std;

string arr[] = {"zero", "one", "two", "three", "four", "five",
				 "six", "seven", "eight", "nine"};
string toString(int n) {
	if(n == 0) 
		return "";
	int x = n%10;
	string s = toString(n/10);
	return s + " " + arr[x];
}

int main() {
	int n;
	cin >> n;
	cout << toString(n);
	return 0;
}