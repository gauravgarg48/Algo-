#include<iostream>
using namespace std;

char keypad[][10] = {"abc", "def", "ghi", "jkl",
				"mno", "pqrs", "tuv", "wx", "yz"};
int c = 0;
void printKeypad(char* in, char* out, int i, int j) {
	if(in[i] == '\0') {
		out[j] = '\0';
		cout << out << " ";
		c++;
		return;
	}

	int digit = in[i]-'1';
	for (int k = 0; keypad[digit][k] != '\0'; ++k) {
		out[j] = keypad[digit][k];
		printKeypad(in, out, i+1, j+1);
	}
}

int main() {
	char in[100], out[100];
	cin >> in;
	printKeypad(in, out, 0, 0);
	cout << endl << c;
	return 0;
}