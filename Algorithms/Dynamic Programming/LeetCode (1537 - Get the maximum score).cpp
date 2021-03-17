const int MOD = 1e9+7;
/*class Solution {
public:
    
    long long int dp[2][int(1e5)][2];
    
    long long int calculate(vector<int>&nums1, vector<int>&nums2, int id, int i, int can_do_bs)
    {
        //cout<<id<<" "<<i<<" "<<can_do_bs<<endl;
        if(i<0 || (id==0 && i>=nums1.size()))
            return 0;
        if(i<0 || (id==1 && i>=nums2.size()))
            return 0;
        
        if(dp[id][i][can_do_bs]==-1)
        {

            if(id==0)
            {
                int idx2 = can_do_bs?lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin():nums2.size();
                //cout<<id<<" "<<i<<" "<<can_do_bs<<" "<<idx2<<endl;
                dp[id][i][can_do_bs] = max(calculate(nums1, nums2,id,i-1, can_do_bs) + nums1[i], 
                                ((idx2!=nums2.size()) && (nums2[idx2]==nums1[i]))?calculate(nums1, nums2, (id+1)%2, idx2, !can_do_bs):(i>0?dp[id][i-1][can_do_bs]:0));
                dp[id][i][can_do_bs] = max(dp[id][i][can_do_bs],calculate(nums1,nums2,id,i-1,!can_do_bs)+nums1[i]);
                //if(i>0)
                    //cout<<dp[id][i-1][can_do_bs]+nums1[i]<<" "<<dp[!id][idx2][!can_do_bs]<<endl;
                //cout<<id<<" "<<i<<" "<<can_do_bs<<" "<<idx2<<" "<<dp[id][i][can_do_bs]<<endl;
            }
            
            else
            {
                int idx1 = can_do_bs?lower_bound(nums1.begin(), nums1.end(), nums2[i]) - nums1.begin():nums1.size();
                //cout<<id<<" "<<i<<" "<<can_do_bs<<" "<<idx1<<endl;
                dp[id][i][can_do_bs] = max(calculate(nums1, nums2,id,i-1, can_do_bs) + nums2[i], 
                                ((idx1!=nums1.size()) && (nums1[idx1]==nums2[i]))?calculate(nums1, nums2, (id+1)%2, idx1, !can_do_bs):(i>0?dp[id][i-1][can_do_bs]:0));
                dp[id][i][can_do_bs] = max(dp[id][i][can_do_bs],calculate(nums1,nums2,id,i-1,!can_do_bs)+nums2[i]);
                //cout<<id<<" "<<i<<" "<<can_do_bs<<" "<<idx1<<" "<<dp[id][i][can_do_bs]<<endl;
            }
        }
        return dp[id][i][can_do_bs];
    }
    
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1, sizeof(dp));
        
        long long int ans=0;
        calculate(nums1,nums2,0,1,true);
        //cout<<dp[1][0][0]<<endl;
        //cout<<dp[0][1][1]<<endl;
        
        for(int i=0;i<nums1.size();i++)
            ans = max(ans, max(calculate(nums1,nums2,0,i,true), calculate(nums1,nums2,0,i,false)));
        
        for(int i=0;i<nums2.size();i++)
            ans = max(ans, max(calculate(nums1,nums2,1,i,true), calculate(nums1,nums2,1,i,false)));
        
        for(int i=0;i<nums1.size();i++)
        {
            cout<<dp[0][i][0]<<" "<<dp[0][i][1]<<endl;
        }
        for(int i=0;i<nums2.size();i++)
        {
            cout<<dp[1][i][0]<<" "<<dp[1][i][1]<<endl;
        }
         return ans%MOD;            
    }
};*/

// Using topological sort

/*class Solution
{
    public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, vector<int>>adj;
        unordered_map<int,int>indegree;
        unordered_map<int, long>values;
        for(int i=0;i<nums1.size();i++)
        {
            indegree[nums1[i]]=0;
            //values[nums1[i]] = nums1[i];
        }
        for(int i=0;i<nums2.size();i++)
        {
            indegree[nums2[i]]=0;
            //values[nums2[i]] = nums2[i];
        }
        for(int i=0;i<nums1.size()-1;i++)
        {
            adj[nums1[i]].push_back(nums1[i+1]);
            indegree[nums1[i+1]]++;
        }
        
        for(int i=0;i<nums2.size()-1;i++)
        {
            adj[nums2[i]].push_back(nums2[i+1]);
            indegree[nums2[i+1]]++;
        }
        
        queue<pair<int,long>>q;//Queue contains all nodes with indegree==0
        
        for(auto p:indegree)
        {
            if(p.second==0)
            {
                q.push({p.first,p.first});
                values[p.first] = p.first;
            }
        }
        //cout<<q.size()<<endl;
        
        while(!q.empty())
        {
            
            auto pp = q.front();
            q.pop();
            for(auto x:adj[pp.first])
            {
            
                values[x] = max(values[x], x + pp.second);
                indegree[x]--;
                if(indegree[x]==0)
                    q.push({x,values[x]});
            }
        }
        long ans = 0;
        
        for(auto p:values)
            ans = max(ans,p.second);
        return ans%MOD;
        
        
    }
};*/

// Using Dp on Tree
class Solution
{
    public:
    unordered_map<int, vector<int>>adj;
    unordered_map<int,long>visited;
    
    long dfs(int x)
    {
        if(visited[x]==0)
        {
            long ans=0;
            for(auto y:adj[x])
            {
                ans = max(ans, dfs(y));

            }
            ans+=x;
            visited[x]=ans;
        }
        return visited[x];
        
    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        
        adj.clear();
        for(int i=0;i<nums1.size()-1;i++)
            adj[nums1[i]].push_back(nums1[i+1]);

        for(int i=0;i<nums2.size()-1;i++)
            adj[nums2[i]].push_back(nums2[i+1]);
        
        long ans = max(dfs(nums1[0]), dfs(nums2[0]));
        return ans%MOD;
            
    }
};

// UsingTwo Pointers


