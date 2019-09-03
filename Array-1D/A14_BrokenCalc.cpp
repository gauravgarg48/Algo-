#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, i;
    vector<int> fact;
    fact.push_back(1);
    cin >> n;
    for(i = 2; i <= n; ++i) {
        for(int k = 0; k < fact.size(); ++k) 
            fact[k] *= i;
        for(int k = 0; k < fact.size(); ++k) {
            if(fact[k] >= 10) {
                if(k+1 == fact.size())
                    fact.push_back(0);
                fact[k+1] += fact[k]/10;
                fact[k] %= 10;
            }
        }
    }
    for(int k = fact.size()-1; k >= 0; --k)
        cout << fact[k];
    return 0;
}