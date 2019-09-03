#include<bits/stdc++.h>
using namespace std;
int main() {
    int i, n, w = 0;
    cin >> n;
    int arr[n], l[n], r[n];
    for(i = 0; i < n; ++i)
        cin >> arr[i];
    l[0] = arr[0];
    r[n-1] = arr[n-1];
    for(i = 1; i < n; ++i)
        l[i] = max(l[i-1], arr[i]);
    for(i = n-2; i >= 0; --i)
        r[i] = max(r[i+1], arr[i]);
    for(i = 0; i < n; ++i)
        w += min(l[i], r[i]) - arr[i];
    cout << w;
	return 0;
}