class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // Same as longest substring without repeating characters.
        set<int>unique;
        vector<int>prefix(nums.size());
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++)
            prefix[i] = prefix[i-1]+nums[i];
        
        int start=0,ans=0;
        for(int end=0;end<nums.size();end++)
        {
            if(unique.count(nums[end]))
            {
                // window already contains nums[start];
                // Start pushing start
                while(true)
                {
                    unique.erase(nums[start++]);
                    if(nums[start-1]==nums[end])
                        break;
                }
            }
            unique.insert(nums[end]);
            ans = max(ans, prefix[end]-(start!=0?prefix[start-1]:0));
        }
        return ans;
    }
};