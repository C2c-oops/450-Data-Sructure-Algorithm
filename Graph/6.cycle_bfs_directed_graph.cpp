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

	//if topo sort exists then it is acyclic
	bool bfsCheck(queue<int> &q, vector<int> &indegree)
	{
		int count = 0;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			count++;

			for (auto adjNode : adjList[node])
			{
				indegree[adjNode]--;
				if (indegree[adjNode] == 0)
					q.push(adjNode);
			}
		}

		if (count == numOfNodes) //--> if topo sort exists
			return false;
		return true;
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
		vector<int> indegree(numOfNodes + 1, 0);
		for (int node = 1; node <= numOfNodes; node++)
			for (auto adjNode : adjList[node])
				indegree[adjNode]++;

		queue<int> q;
		for (int node = 1; node <= numOfNodes; node++)
			if (indegree[node] == 0)
				q.push(node);

		if(bfsCheck(q, indegree))
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