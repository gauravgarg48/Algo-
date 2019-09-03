#include<iostream>
using namespace std;
int main() {
    int n, x, m;
    cin >> n;
    cin >> m;
    n--;
    while(n-- > 0) {
        cin >> x;
        if(x > m)
            m = x;
    }
    cout << m;
	return 0;
}