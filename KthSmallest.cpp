#include <iostream>
#include <vector>
using namespace std;

int kthSmallest(vector<int> arr, int k) {
    int x, i, beg = 0, end = arr.size();
    x = arr[beg];
    vector<int> left;
    vector<int> right;
    for(i = beg+1; i < end; ++i) {
        if(arr[i] < x)
            left.push_back(arr[i]);
        else
            right.push_back(arr[i]);
    }
    x = left.size();
    if(x+1 == k)
        return arr[beg];
    else if(x+1 < k)
        return kthSmallest(right, k-x-1);
    else
        return kthSmallest(left, k);
}

int main() {
	int t, n, k, i;
	cin >> t;
	while(t-- > 0) {
	    cin >> n;
	    vector<int> arr;
	    for(i = 0; i < n; ++i) {
	        cin >> k;
	        arr.push_back(k);
	    }
	    cin >> k;
	    cout << kthSmallest(arr, k) << endl;
	}
	return 0;
}