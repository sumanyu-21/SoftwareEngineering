class Solution {
public:
    int helper(vector<int>&s, int k)
    {
        if(k==0)
            return 0;
        unordered_map<int,int>m;
        int n = s.size();
        int distinct_cnt=0, start=0,end=0;
        int ans=0;
        while(end<n)
        {
            while(end<n && (distinct_cnt<k || (distinct_cnt==k && m[s[end]]!=0))) //end<n used because we are using while loop
            {
                
                // We can move the end pointer.
                if(m[s[end]]==0)
                    distinct_cnt++;
                m[s[end]]++;
                end++;
            }
            //cout<<start<<" "<<end<<" "<<distinct_cnt<<endl;
            while((distinct_cnt==k) || (end==n && start<end))
            {
                ans+=end-start;
                if(--m[s[start]]==0)
                    distinct_cnt--;
                start++;
                
            }
        }
        return ans;
    }
    
    
    int subarraysWithKDistinct(vector<int>& s, int k) {
        //cout<<helper(s,k);
        return helper(s,k)-helper(s,k-1);
    }
};