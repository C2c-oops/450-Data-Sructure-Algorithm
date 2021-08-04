#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
private:
	int numOfNodes;
	int numOfEdges;
	vector<int> *adjList;

	void bfs(int node, vector<int> &visited, vector<int> &ans)
	{
		queue<int> q;
		q.push(node);
		visited[node] = 1;

		while (!q.empty())
		{
			int node = q.front();
			q.pop();

			ans.push_back(node);

			for (auto adjNode : adjList[node])
			{
				if (!visited[adjNode])
				{
					q.push(adjNode);
					visited[adjNode] = 1;
				}
			}
		}
	}

public:
	Graph(int node, int edge)
	{
		this->numOfNodes = node;
		this->numOfEdges = edge;
		adjList = new vector<int>[numOfNodes + 1];
	}

	void inputForGraph()
	{
		for (int edge = 0; edge < numOfEdges; edge++)
		{
			int node, conn;
			cin >> node >> conn;

			adjList[node].push_back(conn);
			adjList[conn].push_back(node);
		}
	}

	void printGraph()
	{
		for (int node = 1; node <= numOfNodes; node++)
		{
			cout << node << ": ";
			for (auto adjNode : adjList[node])
				cout << adjNode << " ";

			cout << endl;
		}
	}

	vector<int> graphTraversal()
	{
		vector<int> ans;
		vector<int> visited(numOfNodes + 1, 0);

		for (int node = 1; node <= numOfNodes; node++)
		{
			if (!visited[node])
			{
				bfs(node, visited, ans);
			}
		}

		return ans;
	}
};

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int node, edge;
	cin >> node >> edge;

	Graph g(node, edge);

	g.inputForGraph();
	g.printGraph();

	for(auto it : g.graphTraversal())
		cout<<it<<" ";

	return 0;
}