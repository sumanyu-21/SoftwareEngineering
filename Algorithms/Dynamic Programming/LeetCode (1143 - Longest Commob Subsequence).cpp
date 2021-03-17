class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001];
        int n1=text1.length();
        int n2=text2.length();
        int max_ans=0;
        if(text1[0]==text2[0])
            dp[0][0]=1;
        else
            dp[0][0]=0;
        for(int j=1;j<n1;j++)
        {
            if(text1[j]==text2[0])
                dp[0][j]=1;
            else
                dp[0][j]=dp[0][j-1];
            max_ans=max(max_ans,dp[0][j]);
        }
        
        for(int i=1;i<n2;i++)
        {
            if(text2[i]==text1[0])
                dp[i][0]=1;
            else
                dp[i][0]=dp[i-1][0];
            max_ans=max(max_ans,dp[i][0]);
        }
        
        for(int i=1;i<n2;i++)
        {
            for(int j=1;j<n1;j++)
            {
                if(text2[i]==text1[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
                 max_ans=max(max_ans,dp[i][j]);
            }
           
        }
        
        /*for(int i=0;i<n2;i++)
        {
            for(int j=0;j<n1;j++)
                cout<<dp[i][j]<<"\t";
            cout<<endl;
        }*/
        return max_ans;
        
    }
};