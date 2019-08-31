#include<bits/stdc++.h>
using namespace std;
class  node {
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
	cin >> d;
	if(d == -1)
		return NULL;

	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void bfs(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		node* tmp = q.front();
		q.pop();
		if(tmp == NULL) {
			cout << endl;
			if(!q.empty())
				q.push(NULL);
		}
		else {
			cout << tmp->data << " ";
			if(tmp->left != NULL)
				q.push(tmp->left);
			if(tmp->right != NULL)
				q.push(tmp->right);
		}
	}
	return;
}

int isBalanced(node* root) {
	if(root == NULL)
		return 0;
	int h1, h2;
	h1 = isBalanced(root->left);
	h2 = isBalanced(root->right);
	if(h1 != -1 && h2 != -1 && abs(h2-h1) <= 1)
		return 1+max(h1, h2);
	else
		return -1;
}

int main() {
	node* root = buildTree();
	bfs(root);
	if(isBalanced(root) > -1)
		cout << "Balanced";
	else
		cout << "Not balanced";
	return 0;
}