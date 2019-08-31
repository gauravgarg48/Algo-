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

int sumReplace(node* root) {
	if(root == NULL)	return 0;
	int x = root->data, sum = 0;
	if(root->left != NULL)
		sum += sumReplace(root->left);
	if(root->right != NULL)
		sum += sumReplace(root->right);;
	if(sum == 0)
		return x;
	root->data = sum;
	return x + sum;
}

int main() {
	node* root = buildTree();
	sumReplace(root);
	bfs(root);
	return 0;
}