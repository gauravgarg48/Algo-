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

	void bfs(T src) {
		queue<T> q;
		map<T, bool> visited;
		q.push(src);
		visited[src] = true;
		while(!q.empty()) {
			T node = q.front();
			cout << node << " ";
			q.pop();
			for(auto i: adjList[node])
				if(!visited[i]) {
					q.push(i);
					visited[i] = true;
				}
		}
		return;
	}

	void dfshelper(T node, map<T,bool> &visited) {
		visited[node] = true;
		cout << node << " ";
		for(auto i: adjList[node])
			if(!visited[i])
				dfshelper(i, visited);
		return;
	}

	void dfs(T src) {
		map<T, bool> visited;
		dfshelper(src, visited);
	}

	void bfs_shortest_path(T src) {
		queue<T> q;
		map<T, int> dist;
		map<T, T> parent;
		for(auto i: adjList)
			dist[i.first] = INT_MAX;
		q.push(src);
		dist[src] = 0;
		while(!q.empty()) {
			T node = q.front();
			cout << node << "." << dist[node] << " ";
			q.pop();
			for(auto i: adjList[node])
				if(dist[i] == INT_MAX) {
					q.push(i);
					dist[i] = dist[node] + 1;
					parent[i] = node;
				}
		}
		return;
	}
};

int main() {
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	g.print();
	g.bfs_shortest_path(0);
	// g.dfs(0);
	return 0;
}