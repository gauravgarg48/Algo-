#include<iostream>
using namespace std;
int main() {
	long a, b, c, ans;
	cin >> a >> b >> c;
	ans = a;
	for(int i = 1; i < b; ++i)
		ans = (ans*a)%c;
	cout << ans%c;
	return 0;
}