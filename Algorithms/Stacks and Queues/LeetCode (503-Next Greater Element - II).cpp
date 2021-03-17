class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int size = nums.size();
        if(nums.size()==0)
            return {};
        stack<pair<int,int>>s;
        s.push({nums[0],0});
        vector<int>ans(size,-1);
        
        for(int i=1;i<size;i++)
        {
            if(nums[i]<=s.top().first)
                s.push({nums[i],i});
            else
            {
                while(!s.empty() && s.top().first<nums[i])
                {
                    ans[s.top().second] = nums[i];
                    s.pop();
                }
                s.push({nums[i],i});
            }
        }
        
        for(int i=0;i<size-1;i++)
        {
            if(nums[i]<=s.top().first)
                s.push({nums[i],i});
            else
            {
                while(!s.empty() && s.top().first<nums[i])
                {
                    ans[s.top().second] = nums[i];
                    s.pop();
                }
                s.push({nums[i],i});
            }
        }
        return ans;
    }
};