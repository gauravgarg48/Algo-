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

node* buildTree(vector<int> v, int s, int e) {
	if(s > e)
		return NULL;
	int m = (s+e)/2;
	node* l = buildTree(v, s, m-1);
	node* r = buildTree(v, m+1, e);
	node* root = new node(v[m]);
	root->left = l;
	root->right = r;
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

int main() {
	int t, n, i, x;
	cin >> t;
	while(t-- > 0) {
		cin >> n;
		vector<int> v;
		for(i = 0; i < n; ++i) {
			cin >> x;
			v.push_back(x);
		}
		node* root = buildTree(v, 0, n-1);
		preorder(root);
		cout << endl;
	}
	return 0;
}