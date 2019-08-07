#include<iostream>
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

int length(Node* head){
	int len = 0;
	while(head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}

void insertAtHead(Node* &head, int x) {
	Node* newNode = new Node(x);
	newNode->next = head;
	head = newNode;
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

void insertInMiddle(Node* &head, int x, int pos) {
	if(head == NULL || pos == 0)
		insertAtHead(head, x);
	else if(pos > length(head))
		insertAtTail(head, x);
	else {
		int jump = 1;
		Node* tmp = head;
		while(jump < pos) {
			jump++;
			tmp = tmp->next;
		}
		Node* newNode = new Node(x);
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
}

void deleteAtHead(Node* &head) {
	if(head == NULL) 
		return;
	Node* tmp = head;
	head = head->next;
	delete tmp;
	return;
}

void deleteAtTail(Node* &head) {
	if(head == NULL) 
		return;
	Node* prev = NULL;
	Node* tmp = head;
	while(tmp->next != NULL) {
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	delete tmp;
	return;
}

void deleteInMiddle(Node* &head, int pos) {
	if(head == NULL || pos < 0)
		return;
	
	int jump = 0;
	Node* tmp = head;
	Node* prev;
	while(jump < pos) {
		jump++;
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = tmp->next;
	delete tmp;
	return;
}

int search(Node* head, int x){
	int i = 1;
	while(head != NULL) {
		if(head->data == x)
			return i;
		head = head->next;
		i++;
	}
	return -1;
}

void reverse(Node* &head){
	Node* prev = NULL;
	Node* cur = head;
	Node* nxt;
	while(cur != NULL) {
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	head = prev;
	return;
}

Node* reverseRec(Node* head){
	if(head->next == NULL || head == NULL)
		return head;

	Node* smallHead = reverseRec(head->next);
	Node* cur = head;
	cur->next->next = cur;
	cur->next = NULL;
	return smallHead;
}

Node* midPoint(Node* head) {
	if(head == NULL || head->next == NULL)
		return head;
	Node* fast = head->next;
	Node* slow = head;
	while(fast!= NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* kthNodeFromLast(Node* head, int k) {
	if(head == NULL || head->next == NULL)
		return head;
	Node* fast = head;
	Node* slow = head;
	while(--k > 0) {
		fast = fast->next;
	}
	while(fast->next != NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

Node* merge(Node* a, Node* b) {
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	
	Node* c;
	if(a->data < b->data) {
		c = a;
		c->next = merge(a->next, b);
	}
	else {
		c = b;
		c->next = merge(a, b->next);
	}
	return c;
}

Node* mergeSort(Node* head) {
	if(head == NULL || head->next == NULL)
		return head;

	Node* mid = midPoint(head);
	Node* a = head;
	Node* b = mid->next;
	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);
	return merge(a, b);
}

bool detectCycle(Node* head) {
	if(head == NULL || head->next == NULL)
		return false;
	Node* fast = head;
	Node* slow = head;
	while(fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow)
			return true;
	}
	return false;
}

void print(Node* head){
	cout << "List: ";
	while(head != NULL) {
		cout << head->data << "->";
		head = head->next;
	}
	cout << endl;
}

void buildList(Node* &head, int n = 4) {
	int x;
	while(n-- > 0){
		cin >> x;
		insertAtTail(head, x);
	}
}

istream& operator>>(istream &is, Node* &head) {
	buildList(head);
	return is;
}

ostream& operator<<(ostream &os, Node* &head) {
	print(head);
	return os;
}

int main() {
	Node* head = NULL;
	Node* head2 = NULL;
	Node* node;
	int i, n, x, ch, p;
	bool exit = true;
	cout << "Build Linked List: ";
	cin >> head;
	cout << head;
	while(exit) {
		cout << "1. Insert 2. Search 3. Delete 4. Reverse "
		<< "5. Display\n6. Midpoint 7. kth Point from Last "
		<< "8. Sort 9. Exit\n";
		cin >> ch;
		switch(ch) {
			case 1:
				cin >> x >> p;
				insertInMiddle(head, x, p-1);
				cout << head;
				break;
			case 2:
				cin >> x;
				cout << search(head, x) << endl;
				break;
			case 3:
				cin >> p;
				deleteInMiddle(head, p);
				cout << head;
				break;
			case 4:
				head = reverseRec(head);
				cout << head;
				break;
			case 5:
				cout << head;
				break;
			case 6:
				node = midPoint(head);
				cout << node->data << endl;
				break;
			case 7:
				cin >> p;
				node = kthNodeFromLast(head, p);
				cout << node->data << endl;
				break;
			case 8:
				head = mergeSort(head);
				cout << head << endl;
				break;
			case 9:
				exit = false;
				break;
			default:
				break;
		}
	}
	return 0;
}