class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>>range;
        for(int i=0;i<nums.size()/2;i++)
        {
            int x = nums[i];
            int y = nums[n-1-i];
            int max_value = limit + max(x,y);
            int min_value = 1+min(x,y);
            range.push_back({min_value, max_value});
            //cout<<min_value<<" "<<max_value<<endl;
        }
        
        vector<int>prefix(2*limit+2,0);
        for(int i=0;i<range.size();i++)
        {
            int min_value = range[i].first;
            int max_value = range[i].second;
            int sum = nums[i]+nums[n-1-i];
            prefix[min_value]+=1;
            prefix[sum]-=1;
            prefix[sum+1]+=1;
            prefix[max_value+1]-=1;
            
            prefix[2]+=2;
            prefix[min_value]-=2;
            
            prefix[max_value+1]+=2;
            prefix[2*limit+1]-=2;
        }
        /*for(int i=0;i<prefix.size();i++)
            cout<<prefix[i]<<" ";
        cout<<endl;*/
        for(int i=1;i<prefix.size();i++)
            prefix[i] = prefix[i-1]+prefix[i];
        
        int ans = INT_MAX;
        for(int i=2;i<=2*limit;i++)
        {
            ans = min(ans, prefix[i]);
            //ans+= prefix[s];
        }
        return ans;
        
    }
};