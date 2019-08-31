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
	int j = s+1;
	while(j <= e) {
		if(v[j] > v[s])
			break;
		j++;
	}
	node* l = buildTree(v, s+1, j-1);
	node* r = buildTree(v, j, e);
	node* root = new node(v[s]);
	root->left = l;
	root->right = r;
	return root;
}

void inRange(node* root, int a, int b) {
	if(root == NULL)
		return;
	inRange(root->left, a, b);
	if(a <= root->data && root->data <= b)
		cout << root->data << " ";
	inRange(root->right, a, b);
	return;
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
	int t, n, i, x, k1, k2;
	cin >> t;
	while(t-- > 0) {
		cin >> n;
		vector<int> v;
		for(i = 0; i < n; ++i) {
			cin >> x;
			v.push_back(x);
		}
		cin >> k1 >> k2;
		node* root = buildTree(v, 0, n-1);
		cout << "# Preorder : ";
		preorder(root);
		cout << endl;
		cout << "# Nodes within range are : ";
		inRange(root, k1, k2);
	}
	return 0;
}