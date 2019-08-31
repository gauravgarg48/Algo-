#include<bits/stdc++.h>
#define N 1000
using namespace std;

bool sumItUp(int arr[], int sol[], int visited[], 
				int i, int j, int n, int t) {
	if(i == n) {
		if(t == 0) {
			for(int k = 0; k < j; ++k)
				cout << sol[k] << " ";
			cout << endl;
		}
		return false;
	}

	if(t >= arr[i] && visited[j]) {
		sol[j] = arr[i];
		visited[j] = 1;
		if(sumItUp(arr, sol, visited, i+1, j+1, n, t-arr[i]))
			return true;
		else
			return sumItUp(arr, visited, sol, i+1, j, n, t);
	}
	else
		return sumItUp(arr, visited, sol, i+1, j, n, t);
	return false;
}

int main() {
	int n, m, i, t;
	cin >> n;
	int arr[N], sol[N], visited[N];
	memset(sol, 0, n*sizeof(int));
	memset(visited, 0, n*sizeof(int));
	for(i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> t;
	sort(arr, arr+n);
	sumItUp(arr, sol, visited, 0, 0, n, t);
	return 0;
}