class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        vector<int>ans(2);
        while(start<end)
        {
            while(end>start && nums[start]+nums[end]>target)
                end--;
            if(nums[start]+nums[end]==target)
            {
                ans = {start+1,end+1};
                break;
            }
            start++;
        }
        return ans;
        
    }
};