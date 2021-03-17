class Solution {
public:
    
    int calculate_cost(int house_id, int last_house, int &prev_cost, int &prev_median, vector<int>&houses)
    {
        if(house_id==last_house)
        {
            prev_cost=0;
            prev_median = last_house;
            return prev_cost;
        }
        
        int new_median = (house_id + last_house)/2;
        
        
        // If number of elements in this range is odd, then median will shift to right by 1.
        // If number of elements in this range is even, the median will remain at the same position.
        
        int new_cost = prev_cost+ houses[last_house] - houses[new_median]; 
       
        if(new_median==prev_median+1)// Odd
        {
            // Calculating left and right array sizes.
            int left_size = new_median-house_id;
            int left_cost = (houses[new_median]-houses[prev_median])* left_size;
            
            int right_size = last_house-prev_median-1;
            int right_cost = (houses[new_median] - houses[prev_median])*right_size;
            
            new_cost = new_cost + left_cost - right_cost ;
        }
        
        prev_cost = new_cost;
        prev_median = new_median;
        return new_cost;
        
    }
    
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
        int n = houses.size();
        vector<int>prefix(n,0);
        prefix[0] = houses[0];
        for(int i=1;i<n;i++)
            prefix[i] = prefix[i-1] + houses[i];
        
        const int inf = 1e9;
        vector<vector<int>>dp(n+1,vector<int>(k+1,inf));
        
        dp[0][0] = 0;
        for(int mail_id=0;mail_id<k;mail_id++)
        {
            for(int house_id=0;house_id<n;house_id++)
            {
                // Update transitions if already computed.
                if(dp[house_id][mail_id]==inf)
                    continue;
                
                int prev_cost = -1, prev_median =-1;
                for(int last_house=house_id;last_house<n;last_house++)
                {
                   
                    int &x = dp[last_house+1][mail_id+1];
                    x = min(x, dp[house_id][mail_id] + calculate_cost(house_id, last_house, prev_cost, prev_median, houses)) ;
                }
            }
        }
        return dp[n][k];
        
    }
};