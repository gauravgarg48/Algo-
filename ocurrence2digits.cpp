// C++ program to count 2s from 0 to n
#include <bits/stdc++.h>
using namespace std;
/* Counts the number of 2s in a number at d-th
   digit */
long long int count2sinRangeAtDigit(long long int number, long long int d);
/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number);
// Driver Coden
int main()
{
    long long int n;
    long long int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout << numberOf2sinRange(n) << endl;
    }
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* Counts the number of 2s in a number at d-th
   digit */
long long int count2sinRangeAtDigit(long long int number, long long int d) {
    number = number%10;
    long long int count = (d-1)*pow(10, d-2);
    if(number == 2)
        count = 2*count + 1;
    else if (number >= 3)
        count = pow(10, d-1) + number*count;
    return count;
}
/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number) {
    long long int count = 0;
    int n = 0;
    while(number > 0) {
        n++;
        count += count2sinRangeAtDigit(number, n);
        number /= 10;
    }
    return count;
}