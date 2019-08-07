#include<iostream>
#include<stack>
using namespace std;

bool checkBP(string s){
	stack<char> st;
	int i, n = s.length();
	for(i = 0; i < n; ++i) {
		if(s[i] == '(')
			st.push(s[i]);
		else if(s.empty() && s[i] == ')' && st.top() != '(')
			return false;
		st.pop();
	}
	return st.empty();
}

int main() {
	string s;
	cin >> s;
	if(checkBP(s))
		cout << "balanced";
	else
		cout << "not balanced";
	return 0;
}