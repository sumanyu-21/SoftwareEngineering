class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>my_map;
        # define n nums.size() 
        int curr_sum = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            curr_sum+=nums[i];
            if(my_map.find(curr_sum)!=my_map.end())
                ans+=my_map[curr_sum];
            
            if(curr_sum==k)
                ans+=1;
            
            my_map[curr_sum + k]+=1;
            
        }
        return ans;
    }
};