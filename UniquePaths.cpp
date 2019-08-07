#include <iostream>
using namespace std;

int totalPaths(int m, int n) {
    if(m < 0 || n < 0)
        return 0;
    if(m == 0 && n == 0)
        return 1;
        
    int count = 0;
    count = totalPaths(m-1, n);
    count += totalPaths(m, n-1);
    return count;
}

int main() {
	int t, n, m;
	cin >> t;
	while(t-- > 0) {
	    cin >> m >> n;
	    cout << totalPaths(m-1, n-1) << endl;
	}
	return 0;
}s