/*int solve(vector<int>& nums)
{
    if(nums.empty())
        return 0;
    
    int n = nums.size();
    vector<int>dp(n,1);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(nums[i]<nums[j])
                dp[j] = max(dp[j], dp[i]+1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}*/

int solve(vector<int>& nums) {
    vector<int>length;
    length.reserve(nums.size());
    for(int i=0;i<nums.size();i++)
    {
        if(length.empty() || length.back()<nums[i])
            length.push_back(nums[i]);
        
        else
        {
            auto itr = lower_bound(length.begin(),length.end(), nums[i]);
            //if(itr!=length.end())
            *itr = nums[i];
        }
    }
    return length.size();
    
}