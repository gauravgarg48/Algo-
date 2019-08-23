#include <bits/stdc++.h>
using namespace std;
class Graph {
    map<int, list<int>> adjList;
public:
	void addEdge(int u, int v) {
		if(u < v)
			adjList[v].push_back(u);
		for(auto j: adjList[u])
			adjList[v].push_back(j);
		return;
	}

	void printConn() {
		for(auto i: adjList)
			printHelper(i.first, i.second, 1);
	}

	void printHelper(int a, list<int> l, int t) {
		if(l.size() == 0)
			return;
		int b = l.front();
		l.pop_front();
		printHelper(a, l, t+1);
		cout << a << " " << b << " " << t << " ";
		return;
	}
};

int main() {
	int t, n, x, i;
	cin >> t;
	while(t-- > 0) {
		Graph g;
		cin >> n;
		for(i = 1; i < n; ++i) {
			cin >> x;
			g.addEdge(x, i+1);
		}
		g.printConn();
	}
	return 0;
}