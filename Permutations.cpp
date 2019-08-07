#include<iostream>
#include<cmath>
using namespace std;

void Perm(string a, int n) {
	if(a[n] == '\0') {
		cout << a << ", ";
		return;
	}
	
	for (int j = n; a[j] != '\0'; ++j) {
		swap(a[j], a[n]);
		Perm(a, n+1);
		swap(a[j], a[n]);
	}
}

void swap(char* a, char* b) {
	char x = *a;
	*a = *b;
	*b = x;
}

int main() {
	string x;
	cin >> x;
	Perm(x, 0);
	return 0;
}