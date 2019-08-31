#include<iostream>
using namespace std;

int func(int n) {
	if(n == 1)
	    return 2;
	if(n == 2)
	    return 3;
	else 
	    return func(n-1) + func(n-2);
}

int main() {
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		cout << "#" << i+1 << " : " << func(n) << endl;
	}
	return 0;
}