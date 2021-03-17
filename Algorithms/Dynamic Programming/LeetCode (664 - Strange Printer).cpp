class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if(n==0)
            return 0;
        const int INF = 1e9+5;
        vector<vector<int>>dp(n,vector<int>(n,INF));
        
        for(int L=n-1;L>=0;L--)
        {
            for(int R=L;R<=n-1;R++)
            {
                if(L==R)
                    dp[L][R] = 1;
                else if(R==L+1)
                    dp[L][R] = s[L]==s[R]?1:2;
                else
                {
                    for(int K = L;K<=R-1;K++)
                        dp[L][R] = min(dp[L][R], dp[L][K]+dp[K+1][R] + (s[L]==s[R]?-1:0));
                }
            }
        }
        return dp[0][n-1];
        
    }
};