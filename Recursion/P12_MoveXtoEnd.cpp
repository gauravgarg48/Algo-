#include<iostream>
using namespace std;

void moveX(string in, int i, int x) {
	if(i == in.length()) {
		while(x-- > 0)
			cout << 'x';
		return;
	}

	if(in[i] == 'x')
		x++;
	else
		cout << in[i];
	moveX(in, i+1, x);
	return;
}

int main() {
	string in;
	cin >> in;
	moveX(in, 0, 0);
	return 0;
}