#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class StackUsingQueue{
private:
	queue<int> *q1;
	queue<int> *q2;
public:
	StackUsingQueue(){
		q1 = new queue<int>();
		q2 = new queue<int>();
	}

	void push(int x) {
		q1->push(x);
	}

	void pop() {
		int n = q1->size();
		for(int i = 0; i < n-1; ++i) {
			q2->push(q1->front());
			q1->pop();
		}
		if(!q1->empty()) {
			q1->pop();
			swap(q1, q2);
		}
	}

	bool empty() {
		return q1->empty();
	}

	int top() {
		int n = q1->size();
		for(int i = 0; i < n-1; ++i) {
			q2->push(q1->front());
			q1->pop();
		}
		int topElement = q1->front();
		if(!q1->empty()) {
			q2->push(q1->front());
			q1->pop();
			swap(q1, q2);
		}
		return topElement;
	}

	~StackUsingQueue() {
		delete q1;
		delete q2;
	}
};

int main() {
	StackUsingQueue<int> s;
	int i, n = 10, x;
	for(i = 0; i < n; ++i)
		s.push(i+'a');
	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}