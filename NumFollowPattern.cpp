#include <iostream>
#include <vector>
using namespace std;

bool printPat(string str, vector<int> out, int i) {
    if(out[i] < 1 || out[i] > 9)
        return false;
    int j;
    if(i == str.length()) {
        for(j = 0; j < out.size(); ++j)
            cout << out[j];
        cout << endl;
        return true;
    }
    if(str[i] == 'I') {
        for(j = out[i]+1; j <= 9; ++j) {
            out.push_back(j);
            if(printPat(str, out, i+1));
                return true;
        }
        return false;
    } else if(str[i] == 'D') {
        for(j = out[i]-1; j >= 0; --j) {
            out.push_back(j);
            if(printPat(str, out, i+1));
                return true;
        }
        return false;
    }
}

int main() {
    int t, n;
    cin >> t;
    string str;
	while(t-- > 0) {
	    cin >> str;
	    vector<int> v;
	    for(int i = 1; i <= 9; ++i){
	        v.push_back(i);
	        if(printPat(str, v, 0))
	            break;
	    }
	}
	return 0;
}