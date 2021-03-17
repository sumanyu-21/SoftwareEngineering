# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

vector<int>pre; // PreOrder Number.
vector<int>low; //Low Link Value
vector<int>bridges
vector<bool>art;

int cnt;

class Graph
{
	int N,M;
	vector<vector<Edge>>adj;

	Graph(int NN)
	{
		M = 0; // Initialise the number of edges to 0.
		N = NN;
		adj.resize(N);
	}

	void add(int i, int j)
	{
		adj[i].push_back(Edge(j,M));
		adj[j].push_back(Edge(i,M));
		M++;
	}
};

class Edge()
{
	int j,id;
	//id is used to handle self loops and parallel edges.
	Edge(int jj, int ii)
	{
		j = jj;
		id = ii;
	}
};

int dfs(Graph &g, int i, int p, int id)
{
	if(pre[i]!=-1) // Backedge
	{
		low[p] = min(low[p], pre[i]) //**Updaing the low link value if we are a backedge**//
		return low[p];
	}
	pre[i] = cnt++;
	low[i] = pre[i];
	bool hasFwd = false; // For articulation Points.

	for (Edge e:g.adj[i])
	{
		if(e.id == id)
			continue; // I don't take the same edge forward and backward, unless it is a parallel arc.

		if(dfs(g, e.j, i, e.id)<0) //<0 tells us that the edge is forward edge.
		{
			low[i] = min(low[i], low[e.j]); //** Updating the Low link value using the subtree if we are a forward edge.**//
			// Update the low link value with the subtree low link value.
			if(low[e.j] == pre[e.j]) // Bridge condition
			{
				bridges.push_back(e.id);
			}

			if(i != p ? low[e.j] >= pre[i] : hasFwd) // If we ar the root node,hasFwd will be true when we have atleast 2 forward edges. First check is for 'Not a Root Node' and second heck is for 'Root Node Case'.
			{
				art[i] = true; // This will become true many times, if it acts as articulation point for many branches.
							   // Coding this ay is useful for biconnected components.
			}

			hasFwd = true; // If we finish exploring atleast one forward edge, we set it to true.
		}
	}
	return -1;
}

int main()
{
	int N,M;
	cin>>N>>M;
	Graph g(N,M);
	low.resize(N);
	pre.resize(N);
	art.resize(N);
	fill(pre.begin(), pre.end(), -1);
	fill(art.begin(), art.end(), -1);
	
	while(M-->0)
	{
		int i,j;
		cin>>i>>j;
		g.add(i-1,j-1);
	}

	for(int i=0;i<g.N;i++)
	{
		if(pre[i]==-1)
		{
			dfs(i, i, g.M);
		}
	}
}