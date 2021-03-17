class Solution {
public:
    
    int dp[1001][1001];

    int longest_palindrome(int i, int j, string &s)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == j)
        {
            dp[i][j] = 1;
            return dp[i][j];
        }
        if (j == i + 1)
        {
            dp[i][j] = s[i] == s[j] ? 2 : 0;
            return dp[i][j];
        }
        dp[i][j] = 0;
        if (longest_palindrome(i + 1, j - 1, s) != 0 && s[i] == s[j])
            dp[i][j] = dp[i + 1][j - 1] + 2;
        return dp[i][j];


    }
    
    string longestPalindrome(string s) 
    {
        
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < s.length(); j++)
                dp[i][j] = -1;
        }
        
    
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                if (dp[i][j] == -1)
                    longest_palindrome(i, j, s);
            }
        }
        int x,y;
        int max_ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                if (dp[i][j] > max_ans)
                {
                    max_ans = dp[i][j];
                    x = i;
                    y = j;
                }
            }
        }
       // cout<<max_ans<< " " << x << " " << y << endl;
        if(max_ans==0)
            return std::string();
        string palindrome = s.substr(x, y - x + 1);
        return palindrome;
    }
};