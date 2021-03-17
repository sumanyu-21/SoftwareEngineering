# include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>LIS(nums.size());
        int n = nums.size();
        LIS[0] = nums[0];
        int LIS_SIZE = 1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>LIS[LIS_SIZE-1])
            {
                LIS[LIS_SIZE] = nums[i];
                LIS_SIZE++;
            }
            else
            {
                auto itr = lower_bound(LIS.begin(), LIS.begin()+LIS_SIZE, nums[i]);
                *itr = nums[i];
            }
           
            
        }
        
        return LIS_SIZE;
        
    }
};