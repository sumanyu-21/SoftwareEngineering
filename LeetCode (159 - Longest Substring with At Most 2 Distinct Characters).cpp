class Solution {
public:
    /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        unordered_map<char,int>distinct;
        int start=0;
        int ans=0;
        int distinct_cnt=0;
        for(int end=0;end<s.size();end++)
        {
            if(distinct_cnt==2 && distinct[s[end]]==0)
            {
                distinct[s[end]]+=1;

                // If we insert his characer, the number of distinct character become 3;
                // Instaed start pulling the start index;
                while(distinct[s[start]]-1!=0)
                {
                    // If we can remove this element, remove it;
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
    
            ans = max(ans, end-start+1);
            cout<<start<<" "<<end<<" "<<ans<<endl;
        }
        return ans;
    }
};