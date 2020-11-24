/*class Solution {
    
    bool isMidSizePossible(int mid , vector<int>&prefix, int s)
    {
        for(int i=mid-1;i<prefix.size();i++)
        {
            if(i==mid-1)
            {
                if(prefix[i]>=s)
                     return true;
            }
               
            else if(prefix[i]-prefix[i-mid]>=s)
                return true;
        }
        return false;
    }
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int>prefix(nums.size(),0);
        prefix[0] = nums[0];
        for(int i= 1;i<nums.size();i++)
            prefix[i] = prefix[i-1] + nums[i];
            
        int left=1, right = nums.size()+1;  // F F F F T T T T T T
        while(left<right)
        {
            int mid = left + (right-left)/2;
            //cout<<mid<<" "<<isMidSizePossible(mid, prefix, s)<<endl;
            if(isMidSizePossible(mid, prefix, s))
                right = mid;
            else
                left = mid+1;
        }
        if(left==nums.size()+1)
            return 0;
        else
            return left;
        
    }
};*/

class Solution{
    public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int curr_sum = 0;
        int ans = INT_MAX;
        while(left<=right && right<n)
        {
            while(right<n && curr_sum<s)
                curr_sum+=nums[right++];
            right--;
            // We haven't found another subarray satisfying the condition, return min size until now.
            if(curr_sum<s)
            {
                if(ans==INT_MAX)
                    return 0;
                else
                    return ans;
            }
            // Right Is pointing to the element where sum exceeds s.
            // Start incrementing left to find out the smallest size subarray
            while(left<=right && curr_sum>=s)
                curr_sum-=nums[left++];
            left--;
            //cout<<left<<" "<<right<<" "<<curr_sum<<endl;
    
            // Now left and right are pointing to the minimum size subarray which is ending at right.
            ans = min(ans, right-left+1);
        
            
            //cout<<left<<" "<<right<<" "<<curr_sum<<endl;
            left++;
            right++;
            
        }
        if(ans==INT_MAX)
            return 0;
        else
            return ans;
        
    }
        
};