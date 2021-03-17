class Solution {
public:
    vector<int> productExceptSelf(vector<int>& temp) 
    {
        int n = temp.size();
        vector<int>nums(temp.size()+1);
        for(int i=1;i<=n;i++)
            nums[i] = temp[i-1];
        
        vector<int>prefix(n+2,1);
        vector<int>suffix(n+2,1);
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i];
            suffix[n-i+1] = suffix[n-i+2] * nums[n-i+1];
        }
        
        vector<int>ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = prefix[i - 1 + 1] * suffix[i + 1 + 1];
        }
        
        return ans;
    }
};