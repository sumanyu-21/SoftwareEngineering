//Approach 1 --> Dynamic Programming O(KN^2)

/*class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>>dp(N+1,vector<int>(K+1,INT_MAX));
        
        for(int j=1;j<=K;j++)
            dp[1][j] = 1;
        
        for(int i=1;i<=N;i++)
            dp[i][1] = i;
        
        for(int i=2;i<=N;i++)
        {
            for(int j=2;j<=K;j++)
            {
                for(int x=1;x<=i;x++)
                {
                        dp[i][j] = min(dp[i][j],max(x-1==0?0:dp[x-1][j-1], i-x==0?0:dp[i-x][j])+1);
                }
            }
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=K;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        cout<<dp[N][K]<<endl;
        return dp[N][K];
        
        
    }
};*/

// Approach 2--> O(KNlogN)

/*class Solution
{
    public:
    
    int binarysearch(int l, int r, int k, vector<vector<int>>&dp)
    {
        int left = l;
        int right = r+1;
        int N = r+1;
        while(left<right)
        {
            int x = left+(right-left)/2;
            
            if(dp[N-x][k]<=dp[x-1][k-1])
                right = x;
            else
                left = x+1;
        }
        if(left==r+1)
            return dp[l][k-1];
        if(left==l)
            return dp[N-1][k];
        else
            return min(dp[left-1][k-1],dp[N-left][k]);
    }
    int superEggDrop(int K, int N) {
        vector<vector<int>>dp(N+1,vector<int>(K+1,INT_MAX));
        
        for(int j=0;j<=K;j++)
            dp[0][j] = 0;
        
        for(int j=1;j<=K;j++)
            dp[1][j] = 1;
        
        for(int i=1;i<=N;i++)
            dp[i][1] = i;
        
        for(int i=2;i<=N;i++)
        {
            for(int j=2;j<=K;j++)
            {
                dp[i][j] = binarysearch(1,i,j, dp)+1;
            }
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=K;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return dp[N][K];
        
    }

    
};*/
        
 
class Solution{
    public:
    int superEggDrop(int K, int N) {
        vector<vector<int>>dp(N+1,vector<int>(K+1,INT_MAX));
        
        for(int j=0;j<=K;j++)
            dp[0][j] = 0;
        
        for(int j=1;j<=K;j++)
            dp[1][j] = 1;
        
        for(int i=1;i<=N;i++)
            dp[i][1] = i;
        
        int x0=1;
        for(int j=2;j<=K;j++)
        {
            int x=1;
            for(int i=2;i<=N;i++)
            {
    
                while(x<i && max(dp[x+1-1][j-1],dp[i-x-1][j])<=max(dp[x-1][j-1],dp[i-x][j]))
                    x++;
                dp[i][j] = max(dp[x-1][j-1], dp[i-x][j])+1;
            }
        }
        return dp[N][K];
    }
    
};



