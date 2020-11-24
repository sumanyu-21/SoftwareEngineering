class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left  = 0, right = n-1;
        if(n==1)
            return nums[0];
        if(nums[0]<nums[n-1])
            return nums[0];
        while(left<right)
        {
            int mid = left + (right-left)/2;
            // We are in the second part of the array
            
            //if(mid!=0  && mid)
            if(nums[mid]<nums[0])
            {
                right = mid;
            }
            // We are in the first part of the array.
            //se if(nums[mid]>nums[0])
            else
                left  = mid+1;
        }
        return nums[right];
        
    }
};