#include<bits/stdc++.h>
using namespace std;
class node {
	public:
		int data;
		node* left;
		node* right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree() {
	int d;
	char f[5];
	cin >> d;
	node* root = new node(d);
	cin >> f;
	if(!strcmp(f, "true"))
		root->left = buildTree();
	cin >> f;
	if(!strcmp(f, "true"))
		root->right = buildTree();
	return root;
}

bool identical(node* r1, node* r2) {
	if(r1 == r2 && r2 == NULL)
		return true;
	if(r1 == NULL || r2 == NULL)
		return false;
	if(r1->data != r2->data)
        return false;
    if(!identical(r1->left, r2->left))
        return false;
    if(!identical(r1->right, r2->right))
        return false;
	return true;
}

int main() {
	node* t1 = buildTree();
	node* t2 = buildTree();
	if(identical(t1, t2))
		cout << "true";
	else
		cout << "false";
	return 0;
}