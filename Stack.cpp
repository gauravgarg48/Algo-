#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class Stack{
private:
	vector<T> v;
public:
	void push(T x) {
		v.push_back(x);
	}

	void pop() {
		if(!empty())
			v.pop_back();
	}

	bool empty() {
		return (v.size() == 0);
	}

	T top() {
		return v[v.size()-1];
	}

	int size() {
		return v.size();
	}
};

template <typename T>
void transfer(Stack<T> &s1, Stack<T> &s2, int n) {
	for (int i = 0; i < n; ++i) {
		s2.push(s1.top());
		s1.pop();
	}
}

template <typename T>
void reverse(Stack<T> &s1) {
	Stack<T> s2;
	int n = s1.size();
	for(int i = 0; i < n; ++i) {
		T x = s1.top();
		s1.pop();
		transfer(s1, s2, n-i-1);
		s1.push(x);
		transfer(s2, s1, n-i-1);
	}
}

template <typename T>
void insertAtBottom(Stack<T> &s, int x) {
	if(s.empty()) {
		s.push(x);
		return;
	}
	int top = s.top();
	s.pop();
	insertAtBottom(s, x);
	s.push(top);
	return;
}

template <typename T>
void reverseRec(Stack<T> &s) {
	if(s.empty())	return;

	int x = s.top();
	s.pop();
	reverseRec(s);
	insertAtBottom(s, x);
}

int main() {
	Stack<char> s;
	int i, n = 10, x;
	for(i = 0; i < n; ++i)
		s.push(i+'a');
	reverseRec(s);
	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	
	return 0;
}