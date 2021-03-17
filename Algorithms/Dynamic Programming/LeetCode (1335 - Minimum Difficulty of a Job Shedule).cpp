class Solution {
public:
    int minDifficulty(vector<int>& a, int d) {
        int n = a.size();
        const int INF = 1e9+5;
        vector<vector<int>>dp(n+1, vector<int>(d+1, INF));
        dp[0][0] = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int curr_day=0;curr_day<d;++curr_day)
            {
                if(dp[i][curr_day]==INF)
                    continue;
                int max_in_interval = a[i];
                for(int j=i+1;j<=n;j++)
                {
                    //cout<<i<<" "<<curr_day<<" "<<j<<endl;
                    max_in_interval = max(max_in_interval, a[j-1]);
                    dp[j][curr_day+1] = min(dp[j][curr_day+1], dp[i][curr_day] + max_in_interval);
                    
                }
            }
        }
        cout<<dp[n][d]<<endl;
        
            
        return (dp[n][d]==INF?-1:dp[n][d]);
    }
};