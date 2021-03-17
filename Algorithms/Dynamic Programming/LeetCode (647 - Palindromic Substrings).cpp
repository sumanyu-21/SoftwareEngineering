int calculate(vector<vector<int>>&dp, int i, int j, string &s)
{
    if(i<0 || j<i || i>s.size() || j>s.size())
        return 0;
    if(i==j)
    {
        dp[i][j]=1;
        return 1;
    } 
    if(j==i+1)
    {
        dp[i][j]=s[i]==s[j]?1:0;
        return dp[i][j];
    }
    if(dp[i][j] ==-1)
    {
        if(s[i]==s[j])
            dp[i][j] = calculate(dp,i+1,j-1,s)!=0?1:0;
            /* max(calculate(dp,i+1,j-1,s)!=0?calculate(dp,i+1,j-1,s)+1:0,
                            max(calculate(dp, i+1,j,s), calculate(dp, i,j-1,s)));*/
        else
            dp[i][j] = 0;//max(calculate(dp, i+1,j,s), calculate(dp, i,j-1,s));
    }
    //cout<<i<<" "<<j<<endl;
    return dp[i][j];
}


class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int> >dp(s.size(), vector<int>(s.size(),-1));
        /*for(int i=0;i<s.size();i++)
            dp[i][i] = 1;*/
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<s.size();j++)
            {
                if(dp[i][j]==-1)
                    calculate(dp,i,j,s);
            }
        }
        calculate(dp,0,s.size()-1,s);
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<s.size();j++)
            {
                ans+=dp[i][j]>=0?dp[i][j]:0;
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        return ans;
        
    }
};