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

node* insert(node* root, int d) {
	if(root == NULL)
		return new node(d);
	if(d <= root->data)
		root->left = insert(root->left, d);
	else
		root->right = insert(root->right, d);
	return root;
}

node* buildTree() {
	int d;
	cin >> d;
	node* root = NULL;
	while(d != -1) {
		root = insert(root, d);
		cin >> d;
	}
	return root;
}

bool search(node* root, int x) {
	if(root == NULL)
		return false;
	if(root->data == x)
		return true;
	if(x <= root->data)
		return search(root->left, x);
	else
		return search(root->right, x);
}

node* deleteNode(node* root, int x) {
	if(root == NULL)
		return root;
	if(root->data == x) {
		if(root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		} if(root->left == NULL && root->right != NULL) {
			node* tmp = root->right;
			delete root;
			return tmp;
		} if(root->left != NULL && root->right == NULL) {
			node* tmp = root->left;
			delete root;
			return tmp;
		}
		node* tmp = root->right;
		while(tmp->left != NULL)
			tmp = tmp->left;
		root->data = tmp->data;
		root->right = deleteNode(root->right, tmp->data);
		return root;
	}
	else if(x <= root->data)
		root->left = deleteNode(root->left, x);
	else
		root->right = deleteNode(root->right, x);
	return root;
}

void levelOrder(node* root) {
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

void inorder(node* root) {
	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
	return;
}

bool isBST(node* root, int min = INT_MIN, int max = INT_MAX) {
	if(root == NULL)
		return true;
	if(root->data >= min && root->data <= max &&
		isBST(root->left, min, root->data) &&
		isBST(root->right, root->data, max))
		return true;
	return false;
}

pair<node*, node*> TreeToList(node* root) {
	pair<node*, node*> p;
	if(root == NULL) {
		p.first = p.second = NULL;
		return p;
	}
	if(root->left == NULL && root->right == NULL) {
		p.first = p.second = root;
		return p;
	}
	if(root->left != NULL && root->right == NULL) {
		pair<node*, node*> l = TreeToList(root->left);
		l.second->right = root;
		p.first = l.first;
		p.second = root;
		return p;
	}
	if(root->left == NULL && root->right != NULL) {
		pair<node*, node*> r = TreeToList(root->right);
		root->right = r.first;
		p.second = r.second;
		p.first = root;
		return p;
	}
	pair<node*, node*> l = TreeToList(root->left);
	pair<node*, node*> r = TreeToList(root->right);
	l.second->right = root;
	root->right = r.first;
	p.first = l.first;
	p.second = r.second;
	return p;
}

int main() {
	node* root = buildTree();
	inorder(root);
	cout << endl;
	levelOrder(root);
	pair<node*, node*> ll = TreeToList(root);
	node* tmp = ll.first;
	while(tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->right;
	}
	return 0;
}