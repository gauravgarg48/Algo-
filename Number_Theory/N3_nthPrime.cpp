#include<bits/stdc++.h>
using namespace std;
int main() {
	const int M = 100000000;
    int n, i, j, count = 1, last = 2;
    bool num[M+1];
    memset(num, true, sizeof(num));

    cin >> n;
    for(i = 3; i <= M && count < n; i+=2) {
        if(num[i]) {
            last = i;
            count++;
            for(j = 2*i; j <= M; j += i)
                num[j] = false;
        }
    }
	cout << last;
	return 0;
}