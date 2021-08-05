#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
	int numOfNodes;
	int numOfEdges;
	vector<int> *adjList;

	bool dfsCheck(int node, vector<int> &visited, vector<int> &dfsVisited)
	{
		visited[node] = 1;
		dfsVisited[node] = 1;

		for (auto adjNode : adjList[node])
		{
			if (visited[adjNode] == 0)
			{
				if (dfsCheck(adjNode, visited, dfsVisited))
					return true;
			}
			else if (dfsVisited[adjNode] == 1)
				return true;
		}

		dfsVisited[node] = 0;
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
		vector<int> dfsVisited(numOfNodes + 1, 0);

		for (int node = 1; node <= numOfNodes; node++)
			if (visited[node] == 0)
				if (dfsCheck(node, visited, dfsVisited))
					return true;
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

	if (g.isCyclic())
		cout << "Cyclic..!";
	else
		cout << "Not Cyclic..!";

	return 0;
}