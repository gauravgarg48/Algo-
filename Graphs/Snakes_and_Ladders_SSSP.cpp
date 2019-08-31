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

	int bfs(T src, T dest) {
		queue<T> q;
		map<T, int> dist;
		map<T, T> parent;
		for(auto i: adjList)
			dist[i.first] = INT_MAX;
		q.push(src);
		dist[src] = 0;
		while(!q.empty()) {
			T node = q.front();
			q.pop();
			for(auto i: adjList[node])
				if(dist[i] == INT_MAX) {
					q.push(i);
					dist[i] = dist[node] + 1;
					parent[i] = node;
				}
		}
		T node = dest;
		while(node != src) {
			cout << node << "<-";
			node = parent[node];
		}
		cout << node << endl;
		return dist[dest];
	}
};

int main() {
	int board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;

	Graph<int> g;
	for(int u = 0; u <= 36; ++u) {
		for(int dice = 1; dice <= 6; ++dice) {
			int v = u+dice+board[u+dice];
			g.addEdge(u, v, false);
		}
	}
	cout << g.bfs(0, 36);
	return 0;
}