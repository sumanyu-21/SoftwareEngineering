class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        
        dp[0][0] = arr[0];
        dp[0][1] = INT_MIN;
        int ans = arr[max_element(arr.begin(), arr.end())-arr.begin()];
        for(int i=1;i<n;i++)
        {
            dp[i][0] = max(dp[i-1][0]+arr[i], arr[i]);
            dp[i][1] = max(dp[i-1][0], (dp[i-1][1]==INT_MIN?INT_MIN:(dp[i-1][1] + arr[i])));
                 
            //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
            ans = max(ans,max(dp[i][0], dp[i][1]));
        }
        
        //ans = INT_MIN;
        return ans;
        
    }
};