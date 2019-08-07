#include<bits/stdc++.h>
using namespace std;
int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool isStr(char **grid, int m, int n, int r, int c, char *str) {
	bool visited[m][n];
	int i, j, k, y, len = strlen(str);
	memset(visited, false, m*n*sizeof(visited[0])); 
	while(len >= 0) {
		for(k = 0; k < 8; ++k) {
			i = r + x[k];
			j = c + y[k];
			if(i >= 0 && j >=0 && i < m && j < n)
		}
		len--;
	}
	if(len < 0)
		return true;
	return false;
}

long findFrequency(char *grid[], int m, int n, char *str) {
	int i, j, count = 0;
	for(i = 0; i < n; ++i) {
		for(j = 0; j < n; ++j) {
			if(isStr(grid, m, n, i, j, str))
				count++;
		}
	}
	return count;
}

int main(){
	int n, m, i, j;
	cin >> m >> n;
	char grid[100][100];
	char str[100];
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			cin >> grid[i][j];
	cin >> str;
	cout << findFrequency(grid, m, n, str);
	return 0;
}