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

void insertNode(Node* &head, int x) {
	Node* cur = head;
	Node* newNode = new Node(x);
	newNode->next = head;

	if(cur != NULL) {
		while(cur->next != head)
			cur = cur->next;
		cur->next = newNode;
	} else {
		newNode->next = newNode;
	}

	head = newNode;
}

void deleteNode(Node* &head, int x) {
	Node* del = head;
	Node* cur;
	Node* next;
	if(del == NULL)
		return;
	while(del->next != head) {
		if(del->data == x)
			break;
		del = del->next;
	}
	if(del->data == x) {
		if(head == del)
			head = del->next;
		cur = head;
		while(cur->next != del)
			cur = cur->next;
		cur->next = del->next;
	} else {
		cout << "Node not present";
		return;
	}
}

void print(Node* head){
	cout << "List: ";
	Node* cur = head;
	while(cur->next != head) {
		cout << cur->data << "->";
		cur = cur->next;
	}
	cout << cur->data << endl;
	return;
}

int main() {
	Node* head = NULL;
	int i, n, x;
	insertNode(head, 10);
	insertNode(head, 20);
	insertNode(head, 30);
	insertNode(head, 40);
	insertNode(head, 50);
	print(head);
	deleteNode(head, 30);
	print(head);
	return 0;
}		