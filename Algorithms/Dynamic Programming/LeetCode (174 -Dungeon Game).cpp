// Using Binary Search and DP
/*# define ll long
class Solution {
    bool isPossible(vector<vector<int>>&arr, int health)
    {
        ll n = arr.size(), m = arr[0].size();
        vector<vector<long>>dp(n, vector<ll>(m,0));
        dp[0][0] = health + arr[0][0];
        if(dp[0][0]<=0)
            return false;
        
        for(int i=1;i<n;i++)
        {
            dp[i][0] = dp[i-1][0]==INT_MIN?INT_MIN:dp[i-1][0] + arr[i][0];
            if(dp[i][0]<=0)
                dp[i][0] = INT_MIN;            
        }
        
        for(int j=1;j<m;j++)
        {
            dp[0][j] = dp[0][j-1]==INT_MIN?INT_MIN:dp[0][j-1] + arr[0][j];
            if(dp[0][j]<=0)
                dp[0][j] = INT_MIN;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(dp[i-1][j] == INT_MIN && dp[i][j-1] == INT_MIN)
                 dp[i][j] = INT_MIN;
                
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + arr[i][j];
                if(dp[i][j]<=0)
                    dp[i][j] = INT_MIN;
                    
            }
        }
        if(dp[n-1][m-1]>0)
            return true;
        else
            return false;
    }
public:
    
    int calculateMinimumHP(vector<vector<int>>& arr) {
        
        int left = 1, right = INT_MAX ; // F F F  F T T T T
        
        while(left<right)
        {
            int  mid = left + (right - left)/2;
            if(isPossible(arr, mid))
                right = mid;
            else
                left = mid+1;
        }
        return left;
        
    }
};*/

// Using Dp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& arr) {
        vector<vector<int>>dp(arr.size(), vector<int>(arr[0].size(),0));
        int n = arr.size();
        int m = arr[0].size();
        
        dp[n-1][m-1] = arr[n-1][m-1]<=0?abs(arr[n-1][m-1])+1:1;
        cout<<dp[n-1][m-1]<<endl;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int req;
                if(i==n-1 && j==m-1)
                    continue;
                if(i==n-1)
                    req = dp[i][j+1]-arr[i][j];
                else if(j==m-1)
                    req = dp[i+1][j]-arr[i][j];
                else
                    req = min(dp[i+1][j], dp[i][j+1])-arr[i][j];
                
                dp[i][j]=req<=0?1:req;
            }
        }
        return dp[0][0];
    }
};