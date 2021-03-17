# include <iostream>
# include <stdio.h>
# include <vector>
# include <algorithm>
# include <unordered_map>
# include <queue>
# include <set>

using namespace std;

struct Node
{
	pair<int, int>parent;
	int size;
};


class DisjointSet
{
	int n;
	int m;
	

	public:
		vector<vector<int>>size;
		vector<vector<pair<int, int>>>parent;
		DisjointSet(int n, int m)
		{
			DisjointSet::n = n;
			DisjointSet::m = m;
			size.resize(n);
			parent.resize(n);
			for (int i = 0; i < n; i++)
			{
				size[i].resize(m);
				parent[i].resize(m);

			}
		}

		void makeSet(int i, int j)
		{
			parent[i][j] = { i,j };
			size[i][j] = 1;
		}

		pair<int,int> findSet(int  i, int j)
		{
			pair<int,int>p = {i,j};
			if(parent[i][j] == p)
				return p;
			
			parent[i][j] = findSet(parent[i][j].first, parent[i][j].second);
			return parent[i][j];
			/*int x = i;
			int y = j;
			pair<int, int>p = { x,y };
			while (parent[x][y] != p)
			{
				int temp = parent[x][y].first;
				y = parent[x][y].second;
				x = temp;
				p = { x,y };
			}
			parent[x][y] = p;
			return p;*/
		}

		void union_set(pair<int,int>u, pair<int,int>v)
		{
			pair<int, int>x = findSet(u.first, u.second);
			pair<int, int>y = findSet(v.first, v.second);

			if (x == y)
				return;
			if (size[x.first][x.second] == size[y.first][y.second])
				swap(x, y);

			parent[y.first][y.second] = { x.first,x.second };
			size[x.first][x.second] += size[y.first][y.second];
		}

};
vector<vector<int>>visited;
vector<int>X = { 1,-1,0,0 };
vector<int>Y = { 0, 0, 1, -1 };
vector<vector<int>>grid;

void bfs(int i, int j,int n,int m, DisjointSet &ob)
{

	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = 1;

	ob.makeSet(i, j);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int new_x = x + X[k];
			int new_y = y + Y[k];
			if (new_x >= 0 && new_x < n && new_y >= 0 && new_y <m && visited[new_x][new_y] == 0)
			{
				q.push({ new_x,new_y });
				visited[new_x][new_y] = 1;
				ob.makeSet(new_x, new_y);
				pair<int, int>p1 = { i,j };
				pair<int, int>p2 = { new_x,new_y };
				ob.union_set(p1, p2);
			}
		}
	}
}


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
    
        visited.resize(n);
        for (int i = 0; i < n; i++)
            visited[i].resize(m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    visited[i][j] = 0;
                else
                    visited[i][j] = -1;
            }
        }

        DisjointSet ob(n, m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                    bfs(i, j,n,m,ob);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    int temp = 0;
                    set<pair<int, int>> s;
                    for (int k = 0; k < 4; k++)
                    {
                        int new_x = i + X[k];
                        int new_y = j + Y[k];

                        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && grid[new_x][new_y]==1)
                        {
                            pair<int, int>parent = ob.findSet(new_x, new_y);
                            if (s.find(parent)== s.end())
                            {
                                temp += ob.size[parent.first][parent.second];
                                s.insert(parent);
                            }
                        }
                    }
                    ans = max(ans, temp+1);
                }

            }
        }
        if (ans == 0)
            ans = n * m;

        cout << ans << endl;
        return ans;
    }
};