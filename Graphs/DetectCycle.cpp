#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
	map<T, list<T>> adjList;
public: 
	Graph() {}

	void addEdge(T u, T v, bool biDir = true) {
		adjList[u].push_back(v);
		if(biDir)
			adjList[v].push_back(u);
	}

	void print() {
		for(auto i: adjList) {
			cout << i.first << "->";
			for(auto j: i.second)
				cout << j << ", ";
			cout << endl;
		}
	}

	bool isCycleBfs(T src) {
		// Undirected graph
		queue<T> q;
		map<T, bool> visited;
		map<T, int> parent;

		q.push(src);
		visited[src] = true;
		parent[src] = src;
		while(!q.empty()) {
			T node = q.front();
			q.pop();
			for(auto i: adjList[node]) {
				if(visited[i] && parent[node] != i)
					return true;
				if(!visited[i]) {
					visited[i] = true;
					parent[i] = node;
					q.push(i);
				}
			}
		}
		return false;
	}

	bool dfshelper(T node, map<T,bool> &visited, map<T,bool> &instack) {
		visited[node] = true;
		instack[node] = true;
		for(auto i: adjList[node]) {
			if(!visited[i])
				return dfshelper(i, visited, instack);
			else if(instack[i])
				return true;
		}
		instack[node] = false;
		return false;
	}

	bool isCycleDfs() {
		// Directed graph
		map<T, bool> visited;
		map<T, bool> instack;
		bool isCycle;
		for(auto i: adjList) {
			T node = i.first;
			if(!visited[node]) {
				isCycle = dfshelper(node, visited, instack);
				if(isCycle)
					return true;
			}
		}
		return false;
	}
};

int main() {
	// Graph<int> g;
	// g.addEdge(0, 1);
	// g.addEdge(0, 4);
	// g.addEdge(1, 2);
	// g.addEdge(2, 3);
	// g.addEdge(2, 4);
	// g.addEdge(3, 4);
	// g.addEdge(3, 5);
	// if(g.isCycleBfs(0))
	// 	cout << "Cyclic";
	// else
	// 	cout << "Non Cyclic";

	Graph<int> g2;
	g2.addEdge(0, 1, false);
	g2.addEdge(0, 2, false);
	g2.addEdge(1, 5, false);
	g2.addEdge(2, 3, false);
	g2.addEdge(2, 4, false);
	g2.addEdge(3, 0, false);
	g2.addEdge(4, 5, false);
	if(g2.isCycleDfs())
		cout << "Cyclic";
	else
		cout << "Non Cyclic";
	return 0;
}