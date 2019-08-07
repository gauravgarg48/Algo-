#include<iostream>
#include<vector>
using namespace std;

void diagonalPrint(int **v, int n, int m) {
    int i, j, k;
    for(k = 0; k < n-1; ++k) {
        i = k;
        j = 0;
        while(i >= 0 && j < m) {
            cout << v[i][j] << " ";
            i--;
            j++;
        }
        cout << endl;
    }
    for(k = 0; k < m; ++k) {
        i = n-1;
        j = k;
        while(i >= 0 && j < m) {
            cout << v[i][j] << " ";
            i--;
            j++;
        }
        cout << endl;
    }
    return;
}

int main() {
	int n, m, i, j;
	cin >> n >> m;
	int **a = new int*[n];
    for(i = 0; i < n; ++i)
        a[i] = new int[m];
	for(i = 0; i < n; ++i)
		for(j = 0; j < m; ++j)
			cin >> a[i][j];
    diagonalPrint(a, n, m);
    return 0;
}