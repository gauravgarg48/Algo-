#include <iostream>
using namespace std;

int main() {
	int t, i, n, x, len, ans;
	string str;
	cin >> t;
	while(t-- > 0) {
	    cin >> str;
	    n = str.length();
	    len = x = ans = 0;
	    for(i = 0; i < n; ++i) {
	        if(str[i] == '(')
	            x++;
            if(str[i] == ')') {
                if(x > 0) {
                    x--;
                    len += 2;
                    if(len > ans)
                        ans = len;
                }
                else if(x == 0)
                    len = 0;
            }
	    }
	    cout << ans << endl;
	}
	return 0;
}