# include <iostream>
# include <bits/stdc++.h>

using namespace std;
int visited[50][50];
int R,C;

int X[4] = [1,-1,0,0];
int Y[4] = [0,0,1,-1];

int dfs(int u, int v)
{
	visited[u][v] = 1;
	for(int i=0;i<4;i++)
	{
		if(u+X[i]>=0 && u+X[i]<C && v+Y[i]>=0 && v+Y[i]<R)
		{
			// If this cell has not been visited and is not blocked.
			if(visited[u+X[i]][v+Y[i]]==0 && mat[u+X[i]][v+Y[i]]==0)
				dfs(u+X[i], v+Y[i]);
		}
	}
	return 0;
}

int main()
{
	int mat[50][50];
	cin>>R>>C;

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
			cin>>mat[i][j];
	}
	memset(visited, visited.size(), 0);
	bfs(0,0);
}