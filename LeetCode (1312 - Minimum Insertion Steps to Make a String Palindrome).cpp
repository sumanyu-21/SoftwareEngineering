/*dp[i][j] = minimum steps to make string (i, j) palindrome;
        dp[i][j] = min(dp[i+1][j] + 1 --> insert character at position j+1,
                       dp[i][j-1] +1 --> insert character at position i-1;*/


// Note - Minimum deletions to make string palindrome is same as minimum insertions to make string palindrome because insertions on one side can be though of as deletions from the other side.

// Another way--> LCS of a string and reverse will be the longest palindrome subsequence for the given string.
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));    
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j)
                    dp[i][j] = 0;
                else
                {
                    if(s[i]==s[j])
                        dp[i][j] = (i+1!=j?dp[i+1][j-1]:0);
                    else
                    {
                        dp[i][j] = min(dp[i+1][j], dp[i][j-1]) +1;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
                       
};