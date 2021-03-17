// Using Binary Search

/*class Solution {
public:
    
    bool isPossible(int k, vector<int>&arr, vector<int>&dp)
    {
        int left = 0, right = k-1;
        // try to remove subarray from left to right
        int n = arr.size();
        while(right<n)
        {
        
            if((left==0?true:dp[left-1]==0) && (right==n-1?true:dp[n-1]-dp[right+1]==0) && ((left==0?INT_MIN:arr[left-1]) <= (right==n-1?INT_MAX:arr[right+1])))
                return true;
            
            right++;
            left++;
        }
        return false;

    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();        
        int left = 0, right = n;
        vector<int>dp(n,0);
        for(int i=1;i<n;i++)
            dp[i] = dp[i-1] + (arr[i]>=arr[i-1]?0:1);
        
        // Binary search on answer.
        while(left<right)
        {
            int mid = left + (right-left)/2;
            
            cout<<mid<<" "<<isPossible(mid,arr,dp)<<endl;
            if(isPossible(mid,arr,dp))
                right = mid;
            else
                left = mid+1;
        }
        return left;
        
    }
};*/

// Using two pointer

class Solution
{
    public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        
        int n = arr.size();
        int left = 0;
        int right = n-1;
        while(left<n-1 && arr[left]<=arr[left+1])
            left++;
        if(left == n-1)
            return 0;
        while(right>0 && arr[right]>=arr[right-1])
            right--;
        if(right==0)
            return n;
        //cout<<left<<" "<<right<<endl;
        int ans = min(n-1-left, right);
        int j = right;
        for(int i=0;i<=left;i++)
        {
            if(arr[i]<=arr[j])
                ans = min(ans, j-i+1-2);
            else
            {
                j++;
                if(j==n)
                    break;
            }
        }
        
        return ans;
    }
    
};