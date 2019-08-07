#include <iostream>
using namespace std;

int fact[10];
int getNum(int x) {
    long sum;
    string s = "", tmp;
    while(true) {
        sum = 0;
        tmp = i;
        while(tmp > 0) {
            sum += fact[tmp%10];
            tmp /= 10;
        }
        if(sum == x)
            break;
        i++;
    }
    return i;
}

int main() {
	int t, n;
	cin >> t;
	fact[0] = 1;
	for(int i = 1; i < 10; ++i)
	    fact[i] = i*fact[i-1];
	while(t-- > 0) {
	    cin >> n;
	    cout << getNum(n) << endl;
	}
	return 0;
}