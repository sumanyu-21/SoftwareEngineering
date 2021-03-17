// Finding Longest simple path(no cycle) in a directed and undirected graph is NP-Hard.
// There must be something special here.

// Here the directed graph does not contain cycles(DAG)
// We can compute longest path in DAG;

// We already have a topologicla sort because we know the order of the nodes.

/*class Solution {
public:
    vector<int> X = {1,-1, 0, 0};
    vector<int> Y = {0,0, 1, -1};
    // Don't need visited array because always going to move to bigger value node.
    int findLongest(int x, int y, vector<vector<int>>&dp, int n, int m, vector<vector<int>>&matrix)
    {
        if(dp[x][y]==-1)
        {
            dp[x][y] = 1;
            for(int i=0;i<4;i++)
            {
                int new_x = x+X[i];
                int new_y = y+Y[i];
                if(new_x>=0 && new_y>=0 && new_x<n && new_y<m && matrix[new_x][new_y]>matrix[x][y])
                {
                    dp[x][y] = max(dp[x][y], findLongest(new_x, new_y, dp, n, m, matrix)+1);
                }
            }
        }
        return dp[x][y];
                
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        
        // dp[i][j] represents maximum path length when starting at node i,j;
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==-1)
                    findLongest(i,j, dp, n, m, matrix);
                        
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};*/

// Can be solved using topological sorting on the directed graph.

class Solution{
    public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        const int H = matrix.size();
        const int W = matrix[0].size();
        vector<vector<int>>values;
        for(int row=0;row<H;row++)
        {
            for(int col=0;col<W;col++)
                values.push_back({matrix[row][col], row, col});
            
        }
        sort(values.begin(), values.end());
        
        vector<vector<int>>distance(H, vector<int>(W,1));
        int ans = 0;
        for(vector<int>value:values)
        {
            int row = value[1];
            int col = value[2];
            ans = max(ans, distance[row][col]);
            for(int r2 = row-1; r2<=row+1;r2++)
            {
                for(int c2 = col-1;c2<=col+1;c2++)
                {
                    if(abs(row-r2) + abs(col-c2)==1)
                    {
                        if(r2>=0 && r2<H && c2>=0 && c2<W && matrix[row][col]<matrix[r2][c2])
                        {
                            distance[r2][c2] = max(distance[r2][c2], distance[row][col]+1);
                            
                        }
                    }
                }
            }
        }
        return ans;
    }
};