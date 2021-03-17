class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>prefix(n,0);
        prefix[0] = nums[0];
        for(int i =1;i<n;i++)
            prefix[i] = prefix[i-1]+nums[i];
        
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int left_sum = prefix[i];
            int right_sum = prefix[n-1]-prefix[i];
            
            ans.push_back((i+1)*nums[i] - prefix[i] + right_sum - (n-1-i)*nums[i]);
        }
        return ans;
    }
};