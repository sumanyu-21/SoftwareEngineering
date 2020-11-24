/*class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        if(n==1)
            return 0;
        while(left<right)
        {
            int mid = left + (right -left)/2;
            
            if(mid!=0 && mid!=n-1 && nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
            {
                return mid;
            }
            bool condition1 = mid!= 0 && mid!= n-1 && nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1];
            bool condition2 = mid==0 && nums[mid]<nums[mid+1];
            if(condition1 || condition2)
                left  = mid+1;
            
            //condition1 = mid!= 0 && mid!= n-1 && nums[mid-1]>nums[mid] && nums[mid]>nums[mid+1];
            //condition2 = mid==n-1 && nums[mid-1]>nums[mid];
            //else if(condition1 || condition2)
            else
                right = mid; 
            // Ideally right should be mid-1;
            // And left = mid+1;
            // But since we are using (left<right), we need to add/subtract 1 to only one update. Otherwise, we may jump left==right condition and go to left>right. This will break the loop but left and right will not point to the same location.
            // Therefore updating only left. But why lef??--> Because if left  = x and right  = x+1,
            // then on updating left  = mid will always give us x, and will cause us to go in infinite loop. Hence adding one to left instead of subtracting one from right.
        
        }
        return left;
        /*if(left!=0 && left!=n-1 && nums[left-1]<nums[left] && nums[left]<nums[left+1])
            return left;
        else 
            return -1;
    }
    
};*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n;  // F F F F F F {T}
                                  // F F F T T T {T}
        while(left<right)
        {
            int mid = left + (right - left)/2;
            if(mid==n-1 || nums[mid]>nums[mid+1])
                right = mid;
            else
                left = mid+1;
        }
        return right;
    }
    
};