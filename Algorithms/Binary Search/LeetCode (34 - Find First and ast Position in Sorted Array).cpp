class Solution {
    int findFirst(const vector<int>& nums, int target)
    {
        int left = 0, right = nums.size(); // Because answer may not lie in the given array;
        while(left<right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid]>=target)
                right = mid;
            else
                left = mid+1;
        }
        return right;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = findFirst(nums,target);
        int b = findFirst(nums, target+1);
        if(a<b)
        {
            return {a, b-1};
        }
        else
            return {-1,-1};
        
    }
};