#include<bits/stdc++.h>
#define N 100
using namespace std;
int *mergeKArrays(int arr[][N],int k);
void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}

int *mergeKArrays(int arr[][N], int k) {
    int *res = new int[N*k];
    int i[k], min, j, n = 0;
    memset(i, 0, k*sizeof(int));
    bool exit = true;
    while(exit) {
        for(j = 0; j < k; ++j)
            if(i[j] < k) {
                min = j;
                break;
            }
        exit = false;
        for(j = 1; j < k; ++j) {
            if(i[j] < k && arr[j][i[j]] <  arr[min][i[min]])
                min = j;
        }
        res[n++] = arr[min][i[min]];
        i[min]++;
        exit = false;
        for(j = 0; j < k; ++j)
            if(i[j] < k)
                exit = true;
    }
    return res;
}