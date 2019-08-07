#include<iostream>
#include<vector>
using namespace std;
long countInversions(vector<int> arr) {
    long swaps = 0;
    int i, j, n = arr.size(), min, key;
    for(i = 0; i < n; ++i) {
        min = i;
        for(j = i+1; j < n; ++j)
            if(arr[j] < arr[min])
                min = j;
            
        if(min != i) {
            swaps += min-i;
            key = arr[min];
            for(j = min; j > i; --j)
                arr[j] = arr[j-1];
            arr[i] = key;
        }
    }
    return swaps;
}

int main(){
	int t;
    cin >> t;
    
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int item;
            cin >> item;
            arr[i] = item;
        }
        long result = countInversions(arr);
        cout << result << "\n";
    }
	return 0;
}