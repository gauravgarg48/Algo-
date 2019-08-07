#include<iostream>
#include<string>
using namespace std;

string removeDuplicates(string s, int i) {
	if(i == s.length()-1)
		return s;
	string res = removeDuplicates(s, i+1);
	if(s[i] == s[i+1])
		res = res.substr(0, i) + res.substr(i+1, s.length()-1);
	return res;
}

int main() { 
	string s;
	cin >> s;
	cout << removeDuplicates(s, 0);
	return 0;
}