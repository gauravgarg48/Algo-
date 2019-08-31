#include<iostream>
#include<string>
using namespace std;

string replacePi(string s, int i) {
	if(i == s.length()-1)
		return s;
	string res = replacePi(s, i+1);
	if(res[i] == 'p' && res[i+1] == 'i')
		res = res.substr(0, i) +
		 "3.14" + res.substr(i+2, res.length()-1);
	return res;
}

int main() {
	int t;
	string s;
	cin >> t;
	while(t-- > 0) {
		cin >> s;
		cout << replacePi(s, 0) << endl;
	}
	return 0;
}