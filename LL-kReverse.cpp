#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
	int data;
	Node* next;	
	Node(int d) {
		data = d;
		next = NULL;
	}
};

Node* kReverse(Node* &head, int k) {
	Node* prev = NULL;
	Node* cur = head;
	Node* end;
	Node* nxt;
	int i = 0;
	while(cur != NULL && i < k) {
		i++;
		nxt = cur->next;
		end = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	head->next = end;
	return prev;
}

void insertAtTail(Node* &head, int x) {
	if(head == NULL) {
		head = new Node(x);
		return;
	}
	Node* tmp = head;
	while(tmp->next != NULL)
		tmp = tmp->next;
	
	tmp->next = new Node(x);
	return;
}

void print(Node* head){
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	Node* head = NULL;
	Node* prev;
	Node* cur;
	int i, n, k, x, len, j;
	cin >> n >> k;
	i = n;
	while(i-- > 0){
		cin >> x;
		insertAtTail(head, x);
	}
	len = n-(n%k);
	head = kReverse(head, k);
	cur = head;
	for(i = k; i < len; i += k) {
		j = 1;
		prev = cur;
		while(j < k) {
			prev = prev->next;
			j++;
		}
		cur = prev->next;
		prev->next = cur = kReverse(cur, k);
	}
	print(head);
	return 0;
}