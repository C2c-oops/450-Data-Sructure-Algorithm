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

	bool bfsCheck(int vertex, vector<int> &visited)
	{
		queue<pair<int, int>> q;
		q.push({vertex, -1});
		visited[vertex] = 1;

		while (!q.empty())
		{
			int node = q.front().first;
			int parent = q.front().second;
			q.pop();

			for (auto adjNode : adjList[node])
			{
				if (visited[adjNode] == 0)
				{
					q.push({adjNode, node});
					visited[node] = 1;
				}
				else if (parent != adjNode)
					return true;
			}
		}
		return false;
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

	bool isCyclic()
	{
		vector<int> visited(numOfNodes + 1, 0);

		for (int node = 1; node <= numOfNodes; node++)
		{
			if (visited[node] == 0)
			{
				if (bfsCheck(node, visited))
					return true;
			}
		}

		return false;
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

	if(g.isCyclic())
		cout<<"Cyclic..!";
	else
		cout<<"Not Cyclic..!";

	return 0;
}