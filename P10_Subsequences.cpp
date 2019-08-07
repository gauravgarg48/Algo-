#include<iostream>
#include <cstring> 
using namespace std;

int x=0;
void subseq(string in, string out, int i) {
	if(i == in.length()) {
		cout << out << " ";
		x++;
		return;
	}
	subseq(in, out, i+1);
	subseq(in, out + in[i], i+1);
	return;
}

int main() {
	string s;
	cin >> s;
	subseq(s, "", 0);
	cout << endl << x;
	return 0;
}