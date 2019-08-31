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

	void dfshelper(T node, map<T,bool> &visited, list<T> &ordering) {
		visited[node] = true;
		for(auto i: adjList[node])
			if(!visited[i])
				dfshelper(i, visited, ordering);
		ordering.push_front(node);
		return;
	}

	void dfsTopologicalSort() {
		map<T, bool> visited;
		list<T> ordering;
		for(auto i: adjList) {
			T node = i.first;
			if(!visited[node])
				dfshelper(node, visited, ordering);
		}
		for(auto i : ordering)
			cout << i << "->";
	}

	void bfsTopologicalSort() {
		map<T, bool> visited;
		map<T, int> indegree;
		queue<T> q;
		for(auto i : adjList) {
			T node = i.first;
			visited[node] = false;
			indegree[node] = 0;
		}
		// Initialize indegree
		for(auto i: adjList) {
			T node = i.first;
			for(auto j: i.second)
				indegree[j]++;
		}
		for(auto i: adjList)
			if(indegree[i.first] == 0)
				q.push(i.first);
		while(!q.empty()) {
			T node = q.front();
			q.pop();
			cout << node << "->";
			for(auto i: adjList[node]) {
				indegree[i]--;
				if(indegree[i] == 0)
					q.push(i);
			}
		}
		return;
	}
};

int main() {
	Graph<string> g;
	g.addEdge("English", "Logic", false);
	g.addEdge("Maths", "Logic", false);
	g.addEdge("Logic", "HTML", false);
	g.addEdge("Logic", "Python", false);
	g.addEdge("Logic", "Java", false);
	g.addEdge("Logic", "JS", false);
	g.addEdge("Python", "WebDev", false);
	g.addEdge("HTML", "CSS", false);
	g.addEdge("CSS", "JS", false);
	g.addEdge("JS", "WebDev", false);
	g.addEdge("Java", "WebDev", false);
	g.addEdge("Python", "WebDev", false);
	g.dfsTopologicalSort();
	cout << endl;
	g.bfsTopologicalSort();
	return 0;
}