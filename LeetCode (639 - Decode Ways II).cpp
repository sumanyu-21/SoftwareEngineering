class Solution {
public:
   int MOD;
   int mod_add(int x, int k)
   {
       int xx = x;
       while(k-1>0)
       {
           x = (x+xx)%MOD;
           k--;
       }
       return x;
   }
    
    int numDecodings(string s) {
        
        MOD = 1e9+7;
        int n = s.length();
        vector<int>dp(n,0);
        if(s[0]=='0')
            dp[0] = 0;
        if(s[0]=='*')
            dp[0] = 9;
        if(s[0]!= '0' && s[0]!='*')
            dp[0] = 1;
    
        for(int i=1;i<n;i++)
        {
            if(dp[i-1]==0)
                return 0;
            
            else if(s[i]=='*')
            {
                dp[i] = (mod_add(dp[i-1],9))%MOD;
                if(s[i-1]=='1')
                    dp[i] = (dp[i] + (i-2>=0?mod_add(dp[i-2],9):9))%MOD;
                
                if(s[i-1]=='2')
                    dp[i] = (dp[i] + (i-2>=0?mod_add(dp[i-2],6):6))%MOD;
                
                if(s[i-1]=='*')
                    dp[i] = (dp[i] + (i-2>=0?mod_add(dp[i-2],15):15))%MOD;
                
            }
            
            else if(s[i]=='0')
            {
                if(s[i-1]=='1' || s[i-1]=='2')
                    dp[i] = (i-2>=0?dp[i-2]:1);
                
                else if(s[i-1]=='*')
                    dp[i] = (i-2>=0?mod_add(dp[i-2],2):2)%MOD;
                else
                    return 0;
            }
            
            else
            {
                dp[i] = dp[i-1];
                
                if(s[i-1]=='1')
                    dp[i] = (dp[i] + (i-2>=0?dp[i-2]:1))%MOD;
                
                if(s[i-1]=='2' && s[i]<='6')
                    dp[i] = (dp[i] + (i-2>=0?dp[i-2]:1))%MOD;
                if(s[i-1]=='*')
                {
                    if(s[i]-'0'<=6)
                        dp[i] = (dp[i] + (i-2>=0?mod_add(dp[i-2],2):2))%MOD;
                    else
                        dp[i] = (dp[i] + (i-2>=0?dp[i-2]:1))%MOD;
                }
                   
            }
        }
        /*for(int i=0;i<n;i++)
            cout<<dp[i]<<" ";*/
        return dp[n-1];
    }
};