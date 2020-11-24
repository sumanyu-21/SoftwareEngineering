class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = INT_MAX/2;
        for(int i=0;i<n-2;i++)
        {
        	for(int j=i+1;j<n-1;j++)
        	{
                
        		int par_sum = nums[i]+ nums[j];
        		int to_find = target - (nums[i]+nums[j]);
                //cout<<par_sum<<" "<<to_find<<endl;
        		auto itr = lower_bound(nums.begin()+j+1, nums.end(), to_find);
        		if(itr!=nums.end())
                {
                    //cout<<target<<endl;
                    if(abs(ans-target)>abs(par_sum + (*itr)-target))
                        ans = par_sum + *itr;
                    //return target;
                }
        		if(itr!=nums.begin() && (itr-1)-nums.begin()>j)
        		{
        			if(abs(ans-target)>abs(par_sum+(*(itr-1))-target))
        				ans = par_sum + (*(itr-1));
                    //cout<<"First "<<*(itr-1)<<ans<<endl;
        		}
            
        		if(itr!=nums.end() && (itr+1)!=nums.end() && (itr+1)-nums.begin()>j)
        		{
        			if(abs(ans-target)>abs(par_sum+(*(itr+1))-target))
        				ans = par_sum + (*(itr+1));
                    //cout<<"Second "<<*(itr+1)<<ans<<endl;
        		}
                //cout<<"Here"<<endl;
        	
            }
        }
        return ans;
    }
};