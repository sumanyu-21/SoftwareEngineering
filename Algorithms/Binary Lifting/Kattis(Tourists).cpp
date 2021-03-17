# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

int N,D; // N- Number of nodes; D- Max Jump Size(2^D)
vector<vector<int>>adj;
vector<vector<int>>par;
vector<int>depth;

void bfs(int s)
{
	vector<bool>seen(N,false);
	queue<int>q;
	seen[s] = true;
	q.push(s);
	depth[s] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v:adj[u])
		{
			if(!seen[v])
			{
				seen[v] = true;
				q.push(v);
				par[0][v] = u;
				depth[v] = depth[u]+1;
			}
		}
	}

}

void binaryLiftingTable()
{
	for(int k=1;k<=D;k++)
	{
		for(int i=0;i<N;i++)
		{
			// First make a jump of 2^(k-1)
			int mid = par[k-1][i];
			if(mid!=-1) // If we do not jump off the table
				par[k][i] = par[k-1][mid];
		}
	}
}

int walk(int i, int x)
{
	// Walk the table by k steps;
	for(int k=0; k<=D;k++)
	{
		if(((1<<k) & x))
			i = par[k][i];
	}
	return i;
}

int lca(int i, int j)
{
	if(depth[i]<depth[j])
		swap(i,j);

	i = walk(i, depth[i]-depth[j]);
	if(i==j)
	 return i;

	for(int k=D;k>=0;k--)
	{
		// Taking Jump only when ancestors ae not equal.
		if(par[k][i]!=par[k][j])
		{
			i = par[k][i];
			j = par[k][j];
		}

	}
	return par[0][i];
}

int dist(int x, int y)
{
	return depth[x] + depth[y] - 2*depth[lca(x,y)] ;
}

int main()
{
	cin>>N;
	adj.resize(N);
	/*for(int i=0;i<N;i++)
		adj[i].reserve(N);*/

	// Read N-1 Edges
	for(int e=1;e<N;e++)
	{
		int x,y;
		cin>>x>>y;
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}

	D = (int)log2(N)+1;
	par.resize(D+1);
	for(int i=0;i<=D;i++)
	{
		par[i].resize(N);
		fill(par[i].begin(), par[i].end(),-1);
	}
	depth.resize(N);
	bfs(0);
	binaryLiftingTable();

	/*for(int k=0;k<=D;k++)
    {

        for(int i=0;i<N;i++)
            cout<<par[k][i]<<" ";
        cout<<endl;
    }*/

	long res = 0;
	for(int i=1;i<=N;i++)
	{
		for(int j=i+i; j<=N;j+=i)
			res+=dist(i-1,j-1)+1;
	}
	cout<<res<<endl;



}
