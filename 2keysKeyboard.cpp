#include<iostream>
#include<stack>
using namespace std;

int minSteps(int n) {
    int i = 0, steps[1001], q1, q2, c = 1;
    steps[0] = 0;   steps[1] = 0;
    steps[2] = 2;   steps[3] = 3;
        
    if(n < 4)
    	return steps[n];
    for(i = 4; i <= n; ++i) {
    	q1 = 1+minSteps(i-c);
    	steps[i] = q1;
    	if(i%2 == 0) {
    		q2 = 2+minSteps(i/2);
    		if(q2 < q1) {
    			steps[i] = q2;
                c = i/2;
            }
        }
        cout << steps[i];
    }
    return steps[n];
}

int main() {
	int n;
	cin >> n;
	cout << minSteps(n);
	return 0;
}