#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct NodeInfo {
	int node;
	float dist;
};

struct NodeCompare {
	bool operator() (const NodeInfo& l, const NodeInfo& r) {
		return l.dist > r.dist;
	}
};

struct Graph {
	vector<vector<pair<int, int>>> adjList; 
	vector<int> nodes;
	Graph(int n) {
		for (int i = 0; i <= n; i++) addNode(i);
	}
	void addNode(int t) {
		nodes.push_back(t);
		adjList.resize(nodes.size());
	}
	void addEdge(int from, int to, int w) {
		adjList[from].push_back({ to, w });
	}
	vector<int> shortestPath(int start, int end) {
		vector<bool> visited(nodes.size(), false);
		vector<float> distances(nodes.size(), 1E20);
		vector<int> parents(nodes.size(), -1);
		priority_queue<NodeInfo, vector<NodeInfo>, NodeCompare> queue;

		distances[start] = 0;
		queue.push({ start, distances[start] });
		while (!queue.empty()) {
			auto [theNode, dist] = queue.top();
			queue.pop();
			if (!visited[theNode]) {
				visited[theNode] = true;
				for (auto [dstNode, edgeDist] : adjList[theNode]) {
					if (distances[dstNode] > dist + edgeDist) {
						distances[dstNode] = dist + edgeDist;
						parents[dstNode] = theNode;
						queue.push({ dstNode, distances[dstNode] });
					}
				}
			}
		}
		vector<int> shortestPath;
		if (visited[end]) {
			int current = end;
			while (current != -1) {
				shortestPath.push_back(current);
				current = parents[current];
			}
		}
		else {
			cerr << "Can`t find path from start to end" << endl;
			return shortestPath;
		}
		reverse(shortestPath.begin(), shortestPath.end());
		return shortestPath;
	}
};

int main(void) {
	int vCnt = 0, eCnt = 0;
	string line;
	ifstream file("USA-road-d.NY.gr.txt");
	if (file.is_open()) file >> vCnt >> eCnt;
	Graph G = Graph(vCnt);
	for (int i = 0; i < eCnt; i++) {
		char a;
		int n1, n2, weight;
		file >> a >> n1 >> n2 >> weight;
		G.addEdge(n1, n2, weight);
	}
	int startNode = 0, endNode = 0;
	cin >> startNode >> endNode;
	auto route = G.shortestPath(startNode, endNode);
	for (auto v : route) cout << v << " ";
	cout << endl;

	file.close();
	return 0;
}