class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char,int>cnt;
        
        int h, start,end,maxLen=0,unique,noLessThanK;
        
        for(int h=1;h<=26;h++)
        {
            cnt.clear();
            start=0,end=0,unique=0,noLessThanK=0;
            
            while(end<s.length())
            {
                //If we can extend the window
                if(unique<=h)
                {
                    if(cnt[s[end]]==0)
                        unique++;
                    cnt[s[end]]++;
                    if(cnt[s[end]]==k)
                        noLessThanK++;
                    
                    end++;
                }
                while(unique>h) // Don't use else condition
                {
                    if(cnt[s[start]]==k)
                        noLessThanK--;
                    cnt[s[start]]--;
                    if(cnt[s[start]]==0)
                        unique--;
                    start++;
                }
                if(unique==h && unique==noLessThanK)
                    maxLen = max(end-start,maxLen);
            }
        }
        return maxLen;
    }
};