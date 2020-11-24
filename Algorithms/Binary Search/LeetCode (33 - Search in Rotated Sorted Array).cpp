/*class Solution {
    int binary_search(int left, int right, int target, vector<int>&nums)
    {
        int ans = -1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                right = mid-1;
            else
                left = mid+1;
        }
        return ans;
        
    }
public:
    int search(vector<int>& nums, int target) {
        // Find pivot element F F F F T T T T (true if nums[i]<nums[0])
        //                    6 7 8 9 1 2 3 4
        int n = nums.size();
        int left = 0, right = n;  // we might have F F (This will take care of n=1) ie, first True might not exist, hence we are taking right = n;
                                  // We might also have 
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid]<nums[0])
                right = mid;
            else
                left = mid+1;
        }
        // If left==0 sorted in increasing order.
        // If left==n, sorted in decreasing order.
        
        // If target<nums[0]--> Search in sorted array in second part
        int pos = -1;
        if(target<nums[0])
            pos = binary_search(left,n-1, target, nums);
        else
            pos = binary_search(0, left-1, target, nums);
        
        return pos;
        
    }
    
    
};*/


// Other wy, without first finding out the pivo element.
// Target  = 6
//[4, 5, 6, 7, 0, 1, 2]
// F, F, T, T, T, T, T

// Target = 3
//[4, 5, 6, 7, 0, 1, 2]
// F, F, F, F, F, F, F

// Target = 7
//[4, 5, 6, 8, 0, 1, 2]
// F, F, F, T, T, T, T


class Solution{
    public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1+1; // Because we might have F F F F F F
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if((target>=nums[0] && (nums[mid]>=target || nums[mid]<nums[0])) ||
               (target<nums[0] && (nums[mid]<nums[0] && nums[mid]>=target)))
                right = mid;
            else
                left = mid+1;
        }
        if(left!=n && nums[left]==target)
            return left;
        else
            return -1;
    }
    
};
