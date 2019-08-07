#include <bits/stdc++.h>
#include<iostream>
using namespace std;
const int MAX = 30;

int cross_subarray(vector<int> arr, int beg, int mid, int end) {
	int lsum = arr[mid], rsum = arr[mid+1], i = mid, sum = 0;
	while(i >= 0) {
		sum += arr[i];
		if(lsum < sum)
			lsum = sum;
		i--;
	}
	sum = 0;
	i = mid+1;
	while(i <= end) {
		sum += arr[i];
		if(rsum < sum)
			rsum = sum;
		i++;
	}
	return lsum+rsum;
}

int max_subarray(vector<int> arr, int beg, int end) {
	if(beg == end)
		return arr[beg];
	int mid = (beg+end)/2, lsum, rsum, csum;
	lsum = max_subarray(arr, beg, mid);
	rsum = max_subarray(arr, mid+1, end);
	csum = cross_subarray(arr, beg, mid, end);
	if(lsum > rsum && lsum > csum)
		return lsum;
	else if(rsum > csum)
		return rsum;
	return csum;
}

vector<int> max_subarray2(vector<int> A) {
	int n = A.size(), imax = -1, jmax = -1, max_sum = 0;
	int icur = 0, jcur = 0, cur_sum = 0;
    while(jcur < n) {
        if(A[jcur] < 0) {
        	cur_sum = 0;
        	icur = jcur+1;
        }
        else {
        	cur_sum += A[jcur];
        	if(max_sum < cur_sum) {
				max_sum = cur_sum;
				imax = icur;
				jmax = jcur+1;
			} else if(max_sum == cur_sum 
				&& jcur - icur + 1 > jmax - imax) {
				imax = icur;
				jmax = jcur+1;
			}
        }
        jcur++;
    }

    vector<int> ans;
    if(imax != -1 && jmax != -1)
    	for(int i = imax; i < jmax; ++i)
    		ans.push_back(A[i]);
    return ans;
}

int main() {
	vector<int> A{1967513926, 1540383426, -1303455736, -521595368};
	vector <int> ans = max_subarray2(A);
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << ' ';
	return 0;
}