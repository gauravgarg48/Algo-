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
		int comp = 1;
		cout << comp << ": ";
		dfshelper(src, visited);
		cout << endl;

		for(auto i: adjList) {
			T node = i.first;
			if(!visited[node]) {
				visited[node] = true;
				comp++;
				cout << comp << ": ";
				dfshelper(node, visited);
			}
		}
	}
};

int main() {
	Graph<string> g;
	g.addEdge("Agra", "Delhi");
	g.addEdge("Amritsar", "Delhi");
	g.addEdge("Amritsar", "Jaipur");
	g.addEdge("Andaman", "Nicobar");
	g.addEdge("Delhi", "Bhopal");
	g.addEdge("Delhi", "Jaipur");
	g.addEdge("Mumbai", "Bhopal");
	g.addEdge("Mumbai", "Bangalore");
	g.addEdge("Mumbai", "Jaipur");
	g.dfs("Agra");
	return 0;
}