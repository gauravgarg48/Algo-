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

node* buildTree(vector<int> pre, int s, int e) {
	if(s > e)
		return NULL;
	int j, x;
	for(j = s+1; j <= e; ++j)
		if(pre[j] > pre[s])
			break;
	node* root = new node(pre[s]);
	root->left = buildTree(pre, s+1, j-1);
	root->right = buildTree(pre, j, e);
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

int main() {
	int d;
	vector<int> arr;
	cin >> d;
	while(d != -1) {
		arr.push_back(d);
		cin >> d;
	}
	node* root = buildTree(arr, 0, arr.size()-1);
	inorder(root);
	cout << endl;
	levelOrder(root);
	return 0;
}