class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        int n= s.length();
        unordered_map<char,int>distinct;
        int start=0,ans=0, distinct_cnt=0;
        for(int end=0;end<s.size();end++)
        {
            if(distinct_cnt==k && distinct[s[end]]==0)
            {
                distinct[s[end]]++;
                while(distinct[s[start]]-1!=0)
                {
                    distinct[s[start++]]--;
                }
                distinct[s[start++]]--;
                
            }
            else
            {
                if(distinct[s[end]]==0)
                    distinct_cnt+=1;
                distinct[s[end]]++;
            }
            ans=max(end-start+1,ans);
        }
        return ans;
    }
};