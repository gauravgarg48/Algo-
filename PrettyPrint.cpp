#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > prettyPrint(int A) {
    int i, j, x, y, n = 2*A-1;
    vector<vector<int> > a;
    for(i = 0; i < n; ++i) {
        vector<int> b;
        for(j = 0; j < n; ++j) {
            x = i;
            y = j;
            if(2*A-2-i < x)
                x = 2*A-2-i;
            if(2*A-2-j < y)
                y = 2*A-2-j;
            if(y < x)
                x = y;
            b.push_back(A-x);
        }
        a.push_back(b);
    }
    return a;
}

int main() {
	int n, i, j;
	cin >> n;
	vector<vector<int>> a;
	a = prettyPrint(n);
	n = a.size();
	for(i = 0; i < n; ++i) {
		for(j = 0; j < n; ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
}