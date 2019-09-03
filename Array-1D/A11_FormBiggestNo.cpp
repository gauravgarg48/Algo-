#include<bits/stdc++.h>
using namespace std;
bool compare(string a, string b) {
    string ab = a.append(b);
    string ba = b.append(a);
    return ab.compare(ba) > 0;
}
int main() {
    int t, n, i;
    cin >> t;
    while(t--) {
        cin >> n;
        string arr[n];
        for(i = 0; i < n; ++i)
            cin >> arr[i];
        sort(arr, arr+n, compare);
        for(i = 0; i < n; ++i)
            cout << arr[i];
        cout << endl;
    }
    return 0;
}