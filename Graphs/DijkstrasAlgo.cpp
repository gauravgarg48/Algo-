#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
	unordered_map<T, list<pair<T, int> >> mMap;
public: 
	Graph() {}

	void addEdge(T u, T v, T w, bool biDir = true) {
		mMap[u].push_back(make_pair(v, w));
		if(biDir)
			mMap[v].push_back(make_pair(u, w));
	}

	void print() {
		for(auto i: mMap) {
			cout << i.first << "->";
			for(auto j: i.second)
				cout << "(" << j.first << ", " << j.second << ")";
			cout << endl;
		}
	}

	void shortest_path(T src) {
		unordered_map<T, int> dist;
		set<pair<int, T> > s;
		
		for(auto i: mMap)
			dist[i.first] = INT_MAX;
		dist[src] = 0;
		s.insert(make_pair(0, src));
		while(!s.empty()) {
			auto p = *(s.begin());
			T node = p.second;
			s.erase(s.begin());
			for(auto i: mMap[node]) {
				if(dist[i.first] > p.first + i.second) {
					T dest = i.first;
					auto f = s.find(make_pair(dist[dest], dest));
					if(f != s.end())
						s.erase(f);
					dist[dest] = p.first + i.second;
					s.insert(make_pair(dist[dest], dest));
				}
			}

		}
		for(auto i: dist)
			cout << i.first << " is located at " << i.second << endl;
		return;
	}
};

int main() {
	Graph<int> g;
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 4);
	g.addEdge(1, 4, 7);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 2);
	g.shortest_path(1);
	return 0;
}