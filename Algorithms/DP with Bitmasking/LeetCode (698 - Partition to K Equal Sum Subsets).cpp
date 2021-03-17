// Enumerating sub masks --O(K* 3^n) but gives TLE.

/*class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(),0);
        if(total%k!=0)
            return false;
        
        int to_find = total/k;
        vector<int>dp(1<<n);
        vector<int>amt(1<<n);
        
        for(int i =0;i<(1<<n);i++)
        {
            dp[i] = false;
            amt[i] = 0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                    amt[i]+=nums[j];
            }
        }
        dp[0] = 1;// Base Case;
        for(int group=1;group<=k;group++)
        {
            for(int mask=0;mask<(1<<n);mask++)
            {
                if(dp[mask])
                int submask = mask;
                
                while(true)
                {
                    dp[mask] = dp[mask] | (dp[mask^submask] && amt[submask]==to_find);
                    if(submask==0)
                        break;
                    submask = (submask-1)&mask;
                }
            }
        }
        return dp[(1<<n)-1];
        
    }
};*/


class Solution
{
    public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
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