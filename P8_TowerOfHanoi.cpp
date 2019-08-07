#include<iostream>
#include<vector>
using namespace std;

void towerOfHanoi(int n, char src, char dest, char help) {
	if(n == 0)
		return;
	
	towerOfHanoi(n-1, src, help, dest);
	cout << "Moving ring " << n << " from " 
		<< src << " to " << dest << endl;
	towerOfHanoi(n-1, help, dest, src);
	return;
	
}

int main() { 
	int n;
	cin >> n;
	towerOfHanoi(n, 'A', 'B', 'C');
	return 0;
}