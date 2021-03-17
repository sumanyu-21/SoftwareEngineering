/*class Solution
{
    bool stoneGame(vector<int>& arr)
    {
        return true;
    }
    
};*/
class Solution {
public:
    bool stoneGame(vector<int>& arr) {
        int n = arr.size();
        int dp[n+1][n+1][2];
        memset(dp,0, sizeof dp);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                dp[i][j][0] = max(dp[i+1][j][1]+arr[i], dp[i][j-1][1]+arr[j]);
                dp[i][j][1] = min(dp[i+1][j][0], dp[i][j-1][0]);
                
            }
        }
        if(dp[0][n-1][0]>dp[0][n-1][1])
            return true;
        return false;
        //cout<<dp[0][n-1][1]<<" "<<dp[0][n-1][0]<<endl;
        //return true;
    }
   
};