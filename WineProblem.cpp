#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> v, int beg, int end, int year) {
    if(beg > end)
        return 0;
    int q1 = v[beg]*year + maxProfit(v, beg+1, end, year+1);
    int q2 = v[end]*year + maxProfit(v, beg, end-1, year+1);
    q1 = max(q1, q2);
    return q1;
}

int main() {
	int i, n, x;
    vector<int> v;
	cin >> n;
    for(i = 0; i < n; ++i) {
        cin >> x;
        v.push_back(x);
    }
	cout << maxProfit(v, 0, n-1, 1);
	return 0;
}