#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class Queue{
private:
	T *arr;
	int f, r, ms, cs;
public:
	Queue(int ds=10) {
		f = 0;
		ms = ds;
		r = ms-1;
		cs = 0;
		arr = new T[ms];
	}

	bool isEmpty() {
		return cs == 0;
	}

	bool isFull() {
		return cs == ms;
	}

	void push(T data) {
		if(!isFull()) {
			r = (r+1)%ms;
			arr[r] = data;
			cs++;
		}
	}

	void pop() {
		if(!isEmpty()) {
			f = (f+1)%ms;
			cs--;
		}
	}

	T getFront() {
		return arr[f];
	}
};

int main() {
	Queue<char> s;
	int i, n = 10, x;
	for(i = 0; i < n; ++i)
		s.push(i+'a');
	while(!s.isEmpty()) {
		cout << s.getFront() << " ";
		s.pop();
	}
	return 0;
}