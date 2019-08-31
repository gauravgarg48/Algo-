#include<iostream>
using namespace std;

int main() {
    int n, i;
    cout << "Enter no of processes: ";
    cin >> n;
    int a[n], b[n], ct[n], wt[n], ta[n];
    cout << "Enter arrival time array: ";
    for(i = 0; i < n; ++i)
        cin >> a[i];
    cout << "Enter burst time array: ";
    for(i = 0; i < n; ++i)
        cin >> b[i];
    ct[0] = b[0];
    for(int i = 1; i < n; ++i)
        ct[i] = b[i] + ct[i-1];
	float tat = 0, w = 0;
    for(int i = 0; i < n; ++i) {
        ta[i] = ct[i] - a[i];
        wt[i] = ta[i] - b[i];
        tat += ta[i];
		w += wt[i];
    }
    cout << "Avg. waiting time: " << w/n;
    cout << "\nAvg. turnaround time: " << tat/n;
    return 0;
}


