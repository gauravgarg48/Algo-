#include <iostream>
using namespace std;

int main(){
	long n,count=1,i,j;
	long long sum = 0;
	cin >> n;
	long arr[n];
	for (i = 0; i < n; ++i)
		cin >> arr[i];
	for (i = 1; i < n; i++) {  
        for (j = 0; j < i; j++) 
            if (arr[i] == arr[j]) 
                break; 
		if (i == j) 
            count++;
    }
	for(i = 1, j = count; i <= count; i++, j--)
		sum=sum+(long)i*j;
    sum %= (1000000007);
	cout << sum << endl;
	return 0;
}