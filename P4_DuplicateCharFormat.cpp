#include<iostream>
#include<string>
using namespace std;

string formatDuplicates(string in, string out, int n) {
	if(n == 0)
		return in[0] + out;
	if(in[n-1] == in[n])
		out = "*" + in[n] + out;
	return formatDuplicates(in, out, n);
}

int main() { 
	string s;
	cin >> s;
	cout << formatDuplicates(s, "", s.length()-1);
	return 0;
}