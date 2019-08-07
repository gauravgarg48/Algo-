#include <bits/stdc++.h> 
using namespace std; 

string lcsRec(string s1, string s2, int n1, int n2) {
    if(n1 < 0 || n2 < 0)
        return "";
    if(s1[n1] == s2[n2]) {
        return lcsRec(s1, s2, n1-1, n2-1) + s1[n1];
    } else {
        string a1, a2;
        a1 = lcsRec(s1, s2, n1-1, n2);
        a2 = lcsRec(s1, s2, n1, n2-1);
        if(a1.length() > a2.length())
            return a1;
        else
            return a2;
    }
}

string LCS(string s1, string s2, int n1, int n2) {
    string arr[n1+1][n2+1];
    int i, j, x1, x2;
    string s;
    for(i = 0; i <= n1; ++i)
        arr[i][0] = "";
    for(i = 1; i <= n2; ++i)
        arr[0][i] = "";
    for(i = 1; i <= n1; ++i) {
        for(j = 1; j <= n2; ++j) {
            if(s1[i-1] == s2[j-1])
                arr[i][j] = arr[i-1][j-1] + s1[i-1];
            else {
                x1 = arr[i-1][j].length();
                x2 = arr[i][j-1].length();
                if(x1 > x2)
                    arr[i][j] = arr[i-1][j];
                else
                    arr[i][j] = arr[i][j-1];
            }
            s = arr[i][j];
        }
    }
    return s;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
    s1 = LCS(s1, s2, s1.length(), s2.length());
    cout << s1;
	return 0;
}