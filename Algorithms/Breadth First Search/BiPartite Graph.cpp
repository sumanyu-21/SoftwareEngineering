# include <iostream>
# include <bits/stdc++.h>

using namespace std;

class Graph{
	int v;
	vector<list<int>>adjList;

public:
	Graph(int v)
	{
		Graph::v = v;
		adjList.resize(v);

	}

	void addEdge(int u, int v)
	{
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	bool isBiPartite(int src)
	{
		queue<int>q;
		vector<int>visited(v,-1);
		// -1 Not visited
		// 0 first set
		// 1 second set.
		q.push(src);
		visited[src] = 0;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(auto node:adjList[u])
			{
				// If the node has not been visited
				if(visited[node]==-1)
				{
					// GIve this node oppossit colour.
					visited[node]= (visited[u]+1)%2;
					q.push(node);
				}
				else if(visited[node]==visited[u])
					return false;

			}
		}
		return true;

	}
};
int main()
{
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(2,0);
	g.addEdge(1,3);
	g.addEdge(2,3);
	bool ans = g.isBiPartite(0);
	if(ans)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

    g.addEdge(0,3);
    ans = g.isBiPartite(0);
	if(ans)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

}
