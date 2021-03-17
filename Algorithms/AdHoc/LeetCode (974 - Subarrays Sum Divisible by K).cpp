class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int K) {
        
        unordered_map<int,int>mymap;
        int curr_sum = 0;
        int ans = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            curr_sum = (curr_sum%K + nums[i]%K + K)%K;
            if(mymap.find(curr_sum)!=mymap.end())
                ans+=mymap[curr_sum];
                
            if(curr_sum==0)
                ans+=1;       
            mymap[curr_sum]+=1;
            
        }
        return ans;
    
    }
};