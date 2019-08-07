#include<bits/stdc++.h>
using namespace std;

void printPrev(char* s) {
	int i, j, n = strlen(s), min = 0;
	char ch;
	for(i = n-2; i >= 0; --i)
		if(s[i+1] < s[i])
			break;
	if(i < 0)
		return;
	for(j = i+1; j < n; ++j) {
		if(s[j] < s[i])
			min = j;
		else
			break;
	}
	ch = s[min];
	s[min] = s[i];
	s[i] = ch;
	sort(s+i+1, s+n, greater<int>());
	cout << s << endl;
	printPrev(s);
	return;
}

int main() {
	char s[100];
	cin >> s;
	printPrev(s);
	return 0;
}