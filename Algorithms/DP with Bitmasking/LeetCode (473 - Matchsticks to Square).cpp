class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int k = 4;
        int n = nums.size();
        if(nums.size()<4)
            return false;
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total%k!=0)
            return 0;
        int to_find = total/k;
        
        vector<int>dp((1<<n),-1);
        vector<int>amt(1<<n,0);
        for(int i=0;i<(1<<n);i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                    amt[i]+=nums[j];
            }
        }
        
        dp[0]=0;
        
        // Iterating over all masks
        for(int mask=0;mask<(1<<n);mask++)
        {
            if(dp[mask]==-1) // I was not able to make transition to this mask. Hence not possible to extend this mask.
                continue;
            
            for(int i=0;i<n;i++)
            {
                if(!(mask&(1<<i)) && dp[mask]+nums[i]<=to_find)
                    dp[mask|(1<<i)] = (dp[mask] + nums[i])%to_find;
            }
            
        }
        if(dp[(1<<n)-1]==0)
            return true;
        return false;
        
    }
};