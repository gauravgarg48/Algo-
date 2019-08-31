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

void preorder(node* root) {
	if(root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
	return;
}

void inorder(node* root) {
	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
	return;
}

void postorder(node* root) {
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
	return;
}

int height(node* root) {
	if(root == NULL)
		return 0;
	return 1+max(height(root->left), height(root->right));
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

void printKthLevel(node* root, int k) {
	if(root == NULL)
		return;
	if(k == 0) {
		cout << root->data << " ";
		return;
	}
	printKthLevel(root->left, k-1);
	printKthLevel(root->right, k-1);
	return;
}

int count(node* root) {
	if(root == NULL)	return 0;
	return 1+count(root->left)+count(root->right);
}

int sum(node* root) {
	if(root == NULL)	return 0;
	return root->data+sum(root->left)+sum(root->right);
}

int main() {
	node* root = buildTree();
	cout << "height: " << height(root) << endl;
	bfs(root);
	cout << "count: " << count(root) << endl;
	cout << "sum: " << sum(root) << endl;
	return 0;
}