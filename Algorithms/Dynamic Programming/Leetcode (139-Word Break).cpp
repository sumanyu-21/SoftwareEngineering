/*class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>str_map;
        for(string s:wordDict)
            str_map.insert(s);
        
        vector<vector<int>>dp(s.length(), vector<int>(s.length(),0));
        
        for(int i=s.length()-1;i>=0;i--)
        {
            for(int j=i;j<s.length();j++)
            {
                if(str_map.find(s.substr(i,j-i+1))!=str_map.end())
                {
                    dp[i][j] = true;
                    continue;
                }
                for(int k=i;k<=j-1;k++)                
                    dp[i][j] = dp[i][j] | (dp[i][k] && dp[k+1][j]);
            }
        }
        return dp[0][s.length()-1];
        
    }
};*/

// Time Complexity-->O(N * WORDS_COUNT * WORDS_LEN)
// Time Complexity==O(|S| * SUM_OF_LENGTHS_IN_DICTIONARY)
/*class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        
        vector<bool>dp(n+1,0);
        //dp[i] = true iff we can split first i characters into strings.
        dp[0] = true;
        for(int i=0;i<s.length();i++)
        {
            if(dp[i])
            {
                for(string d:wordDict)
                {
                    if(i+d.length()<=s.length() && d == s.substr(i,d.length()))
                        dp[i+d.length()] = true;
                }
            }
        }
        
        return dp[n];
    }
};*/

// Time Complexity -->O(|S|*|S|*|S|);
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>str_map;
        for(string ss:wordDict)
            str_map.insert(ss);
        int n = s.length();
        vector<bool>dp(n+1);
        dp[0] = true;
        
        for(int i=0;i<n;i++)
        {
            if(dp[i])
            {
                string tmp = "";
                for(int j=i;j<n;j++)
                {
                    tmp+=s[j];
                    if(str_map.find(tmp)!=str_map.end())
                        dp[j+1] = true;
                }
            }
        }
        return dp[n];
    }
}; // This can be improved. Instead of extending substring and extending it everytime to check if it exists in map or not, we can use hash so that, we would have to only check a single value in map instead of the entire string. Then time complexity will be O(|S| * |S|)

// Another way is to search for the substr in trie of the words in wordDict. Here we wouldn't have to start searching from the root node of the trie everytime. Instead we will just search from the position in trie where previous search for previous substr ended. O(SUM_OF_LENGTH_IN_DIC + N*min(N,LENGTH of Longest string in wordDict))