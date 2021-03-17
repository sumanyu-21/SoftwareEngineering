/*class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        # define arr nums
        int n = nums.size();
        vector<int>prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1; i<n;i++)
            prefix[i] = prefix[i-1] + nums[i];
        
        int left = 0, right = 0;
        int remaining_sum = prefix[n-1] - prefix[0];
        int ans = n;
        while(left<=right && right<n)
        {
            while(right<=n-2 && remaining_sum%p!=0)
            {       
                right++;
                remaining_sum = remaining_sum - arr[right];
            }
            cout<<left<<" "<<right<<" "<<remaining_sum<<endl;
            // Either right will point to n, or somewhere middle
            ans = min(right-left+1, ans);
            while(left<right)
            {
                remaining_sum = remaining_sum + arr[left];
                left++;
                if(remaining_sum%p==0)
                    ans = min(ans, right-left+1);
            }
            cout<<left<<" "<<right<<" "<<remaining_sum<<endl;
            
            
            
        }
        if(ans==n)
            return -1;
        else
            return ans;
       
    }
};*/
/*class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        # define arr nums
        # define ll long long 
        int n = nums.size();
        vector<ll>prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1; i<n;i++)
            prefix[i] = prefix[i-1] + nums[i];
        
        
        ll target = prefix[n-1]%p;
        if(target==0)
            return 0;
        cout<<target<<endl;
        if(prefix[n-1]<target)
            return -1;
        if(nums.size()==1)
        {
            if(target == nums[0])
                return 0;
            else
                return -1;
        }
        
        
        ll left = -1, right = -1;
        ll curr_sum = 0;
        ll ans = LLONG_MAX;
        while(right<n)
        {
            cout<<curr_sum<<endl;
            if(right<=n-2 && curr_sum+arr[right+1]<target)
            {
                curr_sum+=arr[right+1];
                right++;
            }
            if(right==n-1) // No more need to explore
                break;
            curr_sum+= arr[++right];
            
            // right now points to the max subarray with sum >=target
            //cout<<right<<" ";
            //Start moving left pointer
            while(left<right && curr_sum-arr[left+1]>=target)
            {
                curr_sum-=arr[left+1];
                left++; 
            }
            // The element which left points to has not been included in the sum (left, right]
            cout<<left<<" "<<right<<" "<<endl;
            if(curr_sum==target)
            {
                if(left==-1)
                    ans = min(ans, right+1);
                else
                    ans = min(ans, right-left);
                //ans = min(ans, right-left+1);
            }
        
            curr_sum-=arr[left+1];
            left++;
            
            
        }
        if(ans==INT_MAX)
            return -1;
        else
            return ans;
        
    }
};*/
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int target = 0;
        # define n nums.size()
        for(int i=0;i<nums.size();i++)
            target = (target + nums[i]%p)%p;
        
        if(target==0)
            return 0;
        
        unordered_map<int,int>my_map;
        int curr_sum = 0;
        int ans = INT_MAX;
        for(int i=0;i<n;i++)
        {
            curr_sum = (curr_sum + nums[i]%p)%p;
            if(my_map.find(curr_sum)!=my_map.end())
                ans = min(ans, i - my_map[curr_sum]);
            
            if(i!=n-1 && curr_sum == target)
                ans = min(ans, i+1);
            
            my_map[(curr_sum + target)%p] = i;
    
        }
        if(ans==INT_MAX)
            return -1;
        else
            return ans;
    }
};
