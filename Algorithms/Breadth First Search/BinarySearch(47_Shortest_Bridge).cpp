vector<vector<int>>color;
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};

void bfs(int i, int j, int cnt, const int n, const int m, vector<vector<int>>&matrix)
{
    queue<pair<int,int>>q;
    color[i][j] = cnt;
    q.push({i,j});
    while(!q.empty())
    {
        pair<int,int> u = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(u.first + X[i]>=0 && u.first + X[i]<n && u.second+ Y[i]>=0 && u.second+ Y[i]<m)
            {
                if(matrix[u.first + X[i]][u.second+ Y[i]]!=0 && color[u.first + X[i]][u.second + Y[i]]==-1) // If not visited
                {
                    color[u.first + X[i]][u.second + Y[i]] = cnt;
                    q.push({u.first + X[i], u.second + Y[i]});
                }
            }  
        }
    }
    return;
}


int solve(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    color.resize(n);
    for(int i=0;i<n;i++)
    {
        color[i].resize(m);
        fill(color[i].begin(), color[i].end(), -1);
    }
    int cnt = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]!=0 && color[i][j]==-1)
            {
                bfs(i,j, cnt, n, m, matrix);
                cnt++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<color[i][j]<<" ";
        cout<<endl;
    }

    vector<vector<int>>visited(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(color[i][j]!=1)
                visited[i][j] = -1;
        }
    }
    queue<pair<int,int>>q;
    for(int i=0;i<visited.size();i++)
    {
        for(int j=0;j<visited[0].size();j++)
        {
            if(visited[i][j]==0)
                q.push({i,j});
        }
    }

    while(!q.empty())
    {
        pair<int,int>u = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(u.first + X[i]>=0 && u.first + X[i]<n && u.second+ Y[i]>=0 && u.second+ Y[i]<m)
            {
                if(visited[u.first + X[i]][u.second+ Y[i]]==-1) // If not visited
                {
                    visited[u.first + X[i]][u.second + Y[i]] = visited[u.first][u.second]+1;
                    q.push({u.first + X[i], u.second + Y[i]});
                }
            }  
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(color[i][j]==2)
                ans = min(ans, visited[i][j]);
        }
    }
    return ans-1;
    
    
}