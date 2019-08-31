#include<bits/stdc++.h>
using namespace std;
void printPer(string in, string out, int n, int m) {
	if(n == m) {
		cout << out << endl;
		return;
	}
	char ch;
	for(int i = 0; i < in.length(); ++i) {
		ch = in[i];
		if(i == 0 || in[i] != in[i-1]) {
			printPer(in.substr(0, i) + in.substr(i+1, in.length()),
			out+ch, n, m+1);
		}
	}
	return;
}

int main() {
	string s;
	cin >> s;
	int n = s.length();
	sort(s.begin(), s.end());
	printPer(s, "", n, 0);
}