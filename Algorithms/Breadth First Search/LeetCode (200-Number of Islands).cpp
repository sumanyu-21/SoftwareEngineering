vector<vector<char>>grid;
vector<vector<int>>visited(1000, vector<int>(1000));
vector<int>X = { 1,-1,0 ,0 };
vector<int>Y = { 0,0, 1,-1 };

void bfs(int x, int y,int n, int m)
{
	queue<pair<int, int>>my_queue;
	my_queue.push({ x,y });
    visited[x][y] = 1;
	while (!my_queue.empty())
	{
		x = my_queue.front().first;
		y= my_queue.front().second;
        //cout<<x<<" "<<y<<endl;
		my_queue.pop();
		for (int i = 0; i < X.size(); i++)
		{		
			int new_x = x + X[i];
			int new_y = y + Y[i];
			if (new_x >= 0 && new_x <= n - 1 && new_y >= 0 && new_y <= m - 1)
			{
				if (visited[new_x][new_y] == 0)
                {
                    my_queue.push({ new_x,new_y });
                    visited[new_x][new_y]=1;
                }
			}
		
		}
	}
}


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = 0;
        if(n!=0)
            m = grid[0].size();
         //cout<<n<<" "<<m<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '0')
                    visited[i][j] = -1;
                else
                    visited[i][j]=0;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] != 1)
                {
                    bfs(i, j, n,m);
                    ans += 1;
                }
            }
        }
        cout << ans << endl;
        return ans;
    }
};