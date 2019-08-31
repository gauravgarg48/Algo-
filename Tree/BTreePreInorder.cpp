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

node* buildTree(int in[], int pre[], int s, int e) {
	if(s > e)
		return NULL;
	static int i = 0;
	node* root = new node(pre[i]);
	int j;
	for(j = s; j <= e; ++j)
		if(in[j] == pre[i])
			break;
	i++;
	root->left = buildTree(in, pre, s, j-1);
	root->right = buildTree(in, pre, j+1, e);
	return root;
}

int main() {
	int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
	int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
	int n = sizeof(in) / sizeof(int);
	// from preorder and inorder
	node* root = buildTree(in, pre, 0, n-1);
	bfs(root);
	return 0;
}