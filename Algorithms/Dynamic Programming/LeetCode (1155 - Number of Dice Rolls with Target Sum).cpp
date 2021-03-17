/*class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        const int MOD = (int)1e9+7;
        vector<vector<int>>dp(d+1, vector<int>(target+1,0));
        int ans = 0;
        for(int t=1;t<=target;t++)
        {
            if(t<=f)
                dp[1][t] = 1;
        }
        for(int i=2;i<=d;i++)
        {
            for(int t=1;t<=target;t++)
            {
                for(int ff=1;ff<=f;ff++)
                {
                    if(t-ff<=0)
                        continue;
                    
                    if(dp[i-1][t-ff]!=0)
                        dp[i][t] = (dp[i][t] + dp[i-1][t-ff])%MOD;
                }
            }
        }
        return dp[d][target];
        
    }
};*/
/*
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        const int MOD = (int)1e9+7;
        vector<vector<int>>dp(d+1, vector<int>(target+1,0));
        dp[0][0] = 1;
        
        vector<int>prefix_old(target+1,1);
        
        for(int i=1;i<=d;i++)
        {
            vector<int>prefix_new(target+1,0);
            for(int t=1;t<=target;t++)
            {
                dp[i][t] = (prefix_old[t-1] - (t-f-1>=0?prefix_old[t-f-1]:0) + MOD)%MOD;
                prefix_new[t] = (prefix_new[t-1]+  dp[i][t])%MOD;
                
            }
            prefix_old = prefix_new;
        }
        return dp[d][target];
        
    }
};*/

/*
// We just need the previous row of one dimensional array.
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        const int mod = 1e9+7;
        vector<int>ways(target+1);
    
        // dp[s] =the number of ways to get sum 's' so far.
        ways[0] = 1; // Ways to egt sum 0

        for(int rep=1;rep<=d;rep++)
        {
            vector<int>new_ways(target+1);
            for(int already=0; already<=target;already++)
            {
                for(int pipes =1;pipes<=f;pipes++)
                {
                    if(already+pipes<=target)
                    {
                        int &tmp = new_ways[already+pipes];
                        tmp+=ways[already];
                        if(tmp>=mod)
                            tmp-=mod;
                    }
                }
            }

        ways = new_ways;
    }
    return ways[target];
    }
};*/
const int MOD = 1e9+7;
void add(int &a, int b)
{
    a+=b;
    if(a>MOD)
        a-=MOD;
}
class Solution
{
    public:
    
    int numRollsToTarget(int d, int f, int target)
    {
        
        vector<int>ways(target+1);
    
        // ways[s] =the number of ways to get sum 's' so far.
        ways[0] = 1; // Ways to egt sum 0

        vector<int>prefix(target+1,1);
        for(int rep=1;rep<=d;rep++)
        {
            for(int i=1; i<=target;i++)
                add(ways[i],ways[i-1]); // Computees prefix sum.
            
            vector<int>new_ways(target+1);
            for(int new_sum = 1;new_sum<=target;new_sum++)
            {
                // new_sum-f... new_sum-1;
                new_ways[new_sum] = (ways[new_sum-1] - (new_sum-f-1>=0?ways[new_sum-f-1]:0) +MOD)%MOD;
            }
            ways = new_ways;
            
        }
        return ways[target];
    }
};