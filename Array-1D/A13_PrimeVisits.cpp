#include<bits/stdc++.h>
#define N 1000
using namespace std;

int countPrimes(int a, int b) {
    bool num[N+1];
    int primes[N+1], i, j;
    memset(num, true, sizeof(num));
    primes[0] = primes[1] = 0;
    for(i = 2; i <= N; ++i) {
        if(num[i]) {
            for(j = i*i; j <= N; j += i)
                num[j] = false;
            primes[i] = primes[i-1]+1;
        } else
            primes[i] = primes[i-1];
    }
    return primes[b]-primes[a-1];
}

int main() {
    int n, a, b, count, i, j;
    bool flag;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        count = 0;
        for(i = a; i <= b; ++i) {
            if(i < 2)
                continue;
            flag = true;
            for(j = 2; j*j <= i; ++j)
                if(i%j == 0) {
                    flag = false;
                    break;
                }
            if(flag)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}