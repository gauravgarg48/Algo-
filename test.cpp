#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char* abc;
	abc = 'a';
	abc += 'b';
	cout << strlen(abc);
	return 0;
}