#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, i, d;
    string s;
    cin >> s;
    n = s.length();
    d = s[0]-'0';
    if(d >= 5 && d < 9)
        s[i] = 9-d+'0';
    for(i = 1; i < n; ++i) {
        d = s[i]-'0';
        if(d >= 5)
            s[i] = 9-d+'0';
    }
    cout << s;
    return 0;
}