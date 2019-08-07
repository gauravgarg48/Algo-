#include<iostream>
using namespace std;

//char keypad[][10] = {"", "", "abc", "def", "ghi", 
//		"jkl", "mno", "pqrs", "tuv", "wxyz"};
void mappedString(string in, string out, int i) {
	if(i == in.length()) {
		cout << out << endl;
		return;
	}

	int ind1, ind2;
	ind1 = in[i] - '0';
	char ch = 'A' + (ind1-1);
	if(i < in.length()-1 && in[i+1] == '0'
		&& (ind1 == 1 || ind1 == 2)) {
		ch = 'A' + (ind1*10-1);
		mappedString(in, out+ch, i+2);
	}
	else {
		mappedString(in, out+ch, i+1);
		if(i < in.length()-1) {
			ind2 = in[i+1] - '0';
			if(ind1 <= 2 && ind2 <= 6) {
				ch = 'A' + (ind1*10+ind2-1);
				mappedString(in, out+ch, i+2);
			}
		}
	}
	return;
}

int main() {
	string in;
	cin >> in;
	mappedString(in, "", 0);
	return 0;
}