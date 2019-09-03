#include<bits/stdc++.h>
#define N 1009
using namespace std;

void printSum(int *a1, int *a2, int n, int m) {
    int i, j, c = 0, s, k, ans[N];
    s = i = n-1;
    j = m-1;
    while(j >= 0) {
        s = c + a1[i--] + a2[j--];
        c = s/10;
        ans[k--] = s%10;
    }
    while(i >= 0) {
        s = c + a1[i--];
        c = s/10;
        ans[k--] = s%10;
    }
    if(c)
        cout << c << ", ";
    for(i = 0; i < n; ++i)
        cout << ans[i] << ", ";
    cout << "END";
}

int main() {
    int n, m, i;
    cin >> n;
    int a1[N], a2[N];
    for(i = 0; i < n; ++i)
        cin >> a1[i];
    cin >> m;
    for(i = 0; i < m; ++i)
        cin >> a2[i];

    if(n > m)
        printSum(a1, a2, n, m);
    else
        printSum(a2, a1, m, n);
    return 0;
}