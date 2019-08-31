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

int height(node* root) {
	if(root == NULL)
		return 0;
	return 1+max(height(root->left), height(root->right));
}

int diameter(node* root) {
	if(root == NULL)	return 0;
	int d, h1, h2;
	h1 = height(root->left);
	h2 = height(root->right);
	d = max(diameter(root->left), diameter(root->right));
	return max(d, h1+h2);
}

pair<int, int> fastDiameter(node* root) {
	pair<int, int> p;
	if(root == NULL) {
		p.first = p.second = 0;
		return p;
	}
	
	pair<int, int> l, r;
	l = fastDiameter(root->left);
	r = fastDiameter(root->right);
	p.first = 1 + max(l.first, r.first);
	p.second = max(l.first + r.first, max(l.second, r.second));
	return p;
}

int main() {
	node* root = buildTree();
	pair<int, int> p = fastDiameter(root);
	cout << "height: " << p.first << endl;
	cout << "diameter: " << p.second << endl;
	return 0;
}