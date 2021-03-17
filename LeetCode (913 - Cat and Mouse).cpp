/*class Solution {
public:
    int dp[50][50][2];// dp[mouse][cat];
    int visited[50][50][2];
    
    int find(int i, int j, int turn, vector<vector<int>>& graph)
    {      
        
       
        if(dp[i][j][turn]!=-1)
            return dp[i][j][turn];
        
        visited[i][j][turn] = true;
        if(turn==0)
        {
            int flag = 2;
            for(int neigh:graph[i])
            {
                if(!visited[neigh][j][!turn])
                    find(neigh, j, !turn, graph);                        

                
                if(dp[neigh][j][!turn]==1)
                    flag = 1;
                else if((dp[neigh][j][!turn]==0 || dp[neigh][j][!turn]==-1) && flag!=1)
                    flag = 0;
        
            }
            dp[i][j][turn] = flag;
        }
        
        if(turn==1)
        {
            int flag = 1;
            for(int neigh:graph[j])
            {
                if(neigh==0)
                    continue;
                
                if(!visited[i][neigh][!turn])
                    find(i,neigh, !turn, graph);   
                
                if(dp[i][neigh][!turn]==2) // If cat wins.
                    flag = 2;
                else if((dp[i][neigh][!turn]==0 || dp[i][neigh][!turn]==-1) && flag!=2)
                    flag = 0;
            }
            dp[i][j][turn] = flag;
        }
        return dp[i][j][turn];
    }
    
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        const int inf = -1;
        
        memset(dp, -1, sizeof(dp));
        memset(visited, false, sizeof(visited));
        for(int i=1;i<n;i++)
        {
            dp[0][i][1] = 1;
            dp[0][i][0] = 1;
            dp[i][i][0] = 2;
            dp[i][i][1] = 2;
            visited[0][i][1] = visited[0][i][0] = visited[0][i][0] = visited[i][i][1] = true;
        }
        
        find(1,2,0, graph);
        return dp[1][2][0];
        
        
        
    }
};*/

class State
{
    public:
    int m_pos, c_pos, turn;
    State(int m_pos, int c_pos, int turn)
    {
        this->m_pos = m_pos;
        this->c_pos = c_pos;
        this->turn = turn;
        //this->value = value;
    }
};

class Solution
{
    private:
    const int MTurn = 0;
    const int CTurn = 1;
    const int Draw = 0;
    const int MWin = 1;
    const int CWin = 2;
    
    public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n,vector<int>(2, Draw)));
        
        // Indegree with respect to the state graph.
        vector<vector<vector<int>>> indegree(n, vector<vector<int>>(n, vector<int>(2)));
         queue<State>q; // Creating  a quque and processing the states in backward order.
        
        
        for(int i=1;i<n;i++)
        {
            dp[0][i][MTurn] = dp[0][i][CTurn] = MWin;
            dp[i][i][MTurn] = dp[i][i][CTurn] = CWin;
            
            q.emplace(State(0,i,MTurn));
            q.emplace(State(0,i,CTurn));
            q.emplace(State(i,i,MTurn));
            q.emplace(State(i,i,CTurn));
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                indegree[i][j][MTurn] = graph[i].size();
                indegree[i][j][CTurn] = graph[j].size();
                
                if(find(graph[j].begin(), graph[j].end(), 0)!= graph[j].end())
                    indegree[i][j][CTurn]--; // Cat cannot move to the hole and hence decrementing the nodes it can go to.
            }
        }
        
        while(!q.empty())
        {
            int m_pos = q.front().m_pos;
            int c_pos = q.front().c_pos;
            int turn = q.front().turn;
            
            q.pop();
            int prev_turn = !turn;
            int result = dp[m_pos][c_pos][turn];
            
            if(turn==1) // this is Cat's Turn ie previous move must be the mouse turn.
            {
                for(auto i: graph[m_pos]) // Visiting all the inverse edges in the state graph.
                {
                    if(dp[i][c_pos][prev_turn]!=Draw)
                        continue; // We have already computed this state, and hence don't dp anything.
                    
                    if(result == MWin)
                        dp[i][c_pos][prev_turn] = MWin;
                    
                    else
                    {
                        //indegree[i][c_pos][prev_turn]--;
                        if(--indegree[i][c_pos][prev_turn]==0) // All prev positons are not favourable.
                            dp[i][c_pos][prev_turn] = CWin;
                        
                    }
                     if(dp[i][c_pos][prev_turn]!=Draw)
                        q.emplace(State(i,c_pos,prev_turn));
                }
            }
            
            else // This is mouse turn ie prev move must be the cat's turn
            {
                for(auto j:graph[c_pos])
                {
                    if(j==0) continue; // Cat cannot be at hole.
                    if(dp[m_pos][j][prev_turn]!=Draw)
                        continue;
                    
                    if(result == CWin)
                        dp[m_pos][j][prev_turn] = CWin;
                    else
                    {
                        //indegree[m_pos][j][prev_turn]--;
                        if(--indegree[m_pos][j][prev_turn]==0)
                        {
                            dp[m_pos][j][prev_turn] = MWin;
                        }
                    }
                    if(dp[m_pos][j][prev_turn]!=Draw)
                        q.emplace(State(m_pos,j,prev_turn));
                }
            }
        }
        
        return dp[1][2][MTurn];
        
       
        
        
        
    }
};

