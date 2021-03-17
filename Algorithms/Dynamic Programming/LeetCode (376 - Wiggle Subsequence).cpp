/*class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        const int n = a.size();
        vector<vector<int>>dp(n, vector<int>(2));
        //dp[i][0] means we went down to i
        int ans =0;
        for(int i=0;i<n;i++)
        {
            dp[i][0] = dp[i][1] = 1;
            for(int j=0;j<i;j++)
            {
                dp[i][1] = max(dp[i][1], (a[j]<a[i]?dp[j][0]+1:0));
                dp[i][0] = max(dp[i][0], (a[j]>a[i]?dp[j][1]+1:0));
                
            }
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};*/

class Solution{
    public:
    int wiggleMaxLength(vector<int>& a)
    {
        const int n = a.size();
        if(n==0)
            return 0;
        vector<vector<int>>dp(n, vector<int>(2));
        
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
            {
                dp[i][1] = dp[i-1][0]+1;
                dp[i][0] = dp[i-1][0];
            }
            else if(a[i]<a[i-1])
            {
                dp[i][0] = dp[i-1][1]+1;
                dp[i][1] = dp[i-1][1];
            }
            else
            {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            }
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};