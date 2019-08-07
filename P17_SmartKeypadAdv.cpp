#include<iostream>
using namespace std;

string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
char keypad[][10] = {"", "", "abc", "def", "ghi", 
		"jkl", "mno", "pqrs", "tuv", "wxyz"};
void printKeypad(char* in, char* out, int i, int j) {
	if(in[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	int digit = in[i]-'0';
	if(digit == 0)
		printKeypad(in, out, i+1, j);

	for (int k = 0; keypad[digit][k] != '\0'; ++k) {
		out[j] = keypad[digit][k];
		printKeypad(in, out, i+1, j+1);
	}
}

int main() {
	char in[100], out[100];
	cin >> in;
	printKeypad(in, out, 0, 0);
	return 0;
}