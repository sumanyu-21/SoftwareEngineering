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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Graph g(n);

		int e;
		cin>>e;
		for(int i=0;i<e;i++)
		{
			int u,v;
			cin>>u>>v;
			g.addEdge(u,v);
		}
		bool ans = g.isBiPartite(0);
		if(ans)
			cout<<"BICOLORABLE."<<endl;
		else
			cout<<"NOT BICOLORABLE."<<endl;
	}

}
