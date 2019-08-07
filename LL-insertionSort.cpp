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

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insSort(Node* &head, int n) {
    if(head == NULL || head->next == NULL)
        return;
    Node* i = head->next;
    Node* j;
    Node* prevj = NULL;
    Node* previ = head;
    for(i = head->next; i != NULL; i = previ->next) {
        prevj == NULL;
        j = head;
        while (j->next != i && j->data <= i->data) {
            prevj = j;
            j = j->next;
        }
        if(previ->next == i)
            previ = i;
        if (j->data < i->data)
            continue;
        previ->next = i->next;
        if(prevj == NULL) {
            head = i;
            i->next = j;
        }
        else {
            i->next = j;
            prevj->next = i;
        }
        print(head);
    }
    return;
}

int main() {
    Node* head = NULL;
    int i, n, x;
    cin >> n;
    i = n;
    while(i-- > 0){
        cin >> x;
        insertAtTail(head, x);
    }
    insSort(head, n);
    cout << "3" << endl;
    print(head);
    return 0;
}