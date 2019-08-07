#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

int x=0;
vector<string> substrings(string in, int i) {
	vector<string> v1;
	if(i == in.length())
		return v1;
	
	v1 = substrings(in, i+1);
	string out = "";
	for(int j = i; j < in.length(); ++j) {
		out += in[j];
		v1.push_back(out);
	}
	return v1;
}

int main() {
	string s;
	int i, n;
	cin >> s;
	vector<string> v;
	v = substrings(s, 0);
	n = v.size();
	for(i = 0; i < n; ++i)
		cout << v[i] << ".";
	cout << n;
	return 0;
}