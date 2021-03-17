// DP Solution O(n^3)--> can be reduced to O(n^2)
/*class Solution {
public:
    int maxSatisfaction(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,INT_MIN));
        
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            dp[i][1] = nums[i];
            ans=max(ans,dp[i][1]);
        }
        for(int dish=0;dish<nums.size();dish++)
        {
            for(int time=2;time<=dish+1;time++)
            {
                for(int prev_dish=0;prev_dish<dish;prev_dish++)
                    dp[dish][time] = max(dp[dish][time],prev_dish+1>=time-1?dp[prev_dish][time-1]+nums[dish]*time:INT_MIN);
                ans = max(ans,dp[dish][time]);
                    
            }
        }
        return ans;
        
        
    }
};*/

class Solution {
public:
    int maxSatisfaction(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int total=0;
        int res = 0;
        for(int i=nums.size()-1;i>=0 && nums[i]+total>=0;i--)
        {
            total+=nums[i];
            res+=total;
        }
        
        return res;
    }
};