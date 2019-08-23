#include<bits/stdc++.h>
using namespace std;
int main() {
    long x, p = INT_MAX;
    int i, n, m = -1;
    cin >> n;
    for(i = 0; i < n; ++i) {
        cin >> x;
        if(m == -1 && p < x)
            m = 1;
        if(m == 1 && p > x)
            break;
        p = x;
    }
    if(i < n)
        cout << "false";
    else
        cout << "true";
	return 0;
}