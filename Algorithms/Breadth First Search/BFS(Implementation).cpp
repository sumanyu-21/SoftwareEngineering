# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	vector<list<int> >adjList;
	vector<int>dist;
	vector<int>parent;

public:
	Graph(int v)
	{
		Graph::v = v;
		adjList.resize(v);
		dist.resize(v);
		parent.resize(v,-1);
	}

	void addEdge(int u, int v, bool bidir=true)
	{
		adjList[u].push_back(v);
		if(bidir)
			adjList[v].push_back(u);
	}

	void bfs(int src)
	{
		// Traverse all the nodes.
		queue<int>q;
		vector<bool>visited(v,false);
		q.push(src);
		visited[src] = true;
		dist[src] = 0;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			cout<<u<<endl;
			for(auto node:adjList[u])
			{
				if(visited[node]==false)
				{
					q.push(node);
					visited[node] = true;
					dist[node] = dist[u] + 1;
					parent[node] = u;
				}
			}
		}
	}

	void printDistance()
	{
        for(int i=0;i<v;i++)
            cout<<i<<" "<<dist[i]<<endl;
	}

	void printPath(int src, int dest)
	{
        list<int>path;
        int temp = dest;
        while(temp!=-1)
        {
            path.push_front(temp);
            temp = parent[temp];
        }
        cout<<"shortest path from src to dist is"<<endl;
        for(auto x:path)
            cout<<x<<" ";

	}

};

int main()
{
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(3,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(4,3);

	g.bfs(0);
	g.printDistance();
	g.printPath(0,5);
}
