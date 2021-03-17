/*
[2, 3, 4, 1, 5]
[2, 5, 9, 10, 15]

0, 3, 4, 1, 5, 0, 1, 2;
0, 3, 7, 8, 13, 13, 14, 16;
0, 3, 10, 18, 
*/

/*class Solution {
    

public:
    vector<int>calculate_prefix_sum(vector<int>&arr)
    {
        vector<int>prefix(arr.size(),0);
        prefix[0] = 0;
        for(int i=1;i<prefix.size();i++)
            prefix[i] = prefix[i-1]+arr[i];
        return prefix;
    }
    vector<int>calculate_suffix_sum(vector<int>&arr)
    {
        vector<int>suffix(arr.size(),0);
        suffix[arr.size()-1] = arr.back();
        for(int i=arr.size()-2;i>=0;i--)
            suffix[i] = suffix[i+1]+arr[i];
        return suffix;
        
    }
    int minMoves(vector<int>& nums, int k) {
        
        stack<int>s;
        vector<int>prefix;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                s.push(i);
            else
            {
                while(!s.empty() && nums[s.top()]==0)
                {
                    s.pop();
                }
                if(s.empty())
                    prefix.push_back(0);
                else
                    prefix.push_back(i-s.top()-1);
                s.push(i);
            }
        }
        vector<int>suffix(prefix.size(),0);
        for(int i=0;i<prefix.size()-1;i++)
            suffix[i] = prefix[i+1];
        
        vector<int>prefix2(prefix.size(),0);
        vector<int>prefix3(prefix.size(),0);
        vector<int>suffix2(suffix.size(), 0);
        vector<int>suffix3(suffix.size(), 0);
        
        prefix2 = calculate_prefix_sum(prefix);
        prefix3 = calculate_prefix_sum(prefix2);
        suffix2 = calculate_suffix_sum(suffix);
        
        suffix3 = calculate_suffix_sum(suffix2);
        
       
        int ans = INT_MAX;
        for(int i=0;i<prefix.size();i++)
        {
            if(i+k-1<prefix.size())
            {
                // Find median;
                int median = i+(k+1)/2-1;

                int result_right = prefix3[i+k-1] - prefix3[median] - prefix2[median]*(i+k-1 - (median+1) +1);
                int result_left = suffix3[i] - suffix3[median] - suffix2[median]*(median-1 - i +1);
                
                ans = min(ans, result_left+result_right);
            }
        }
        return ans;
    }
};*/

class Solution{
    public:
    
    int minMoves(vector<int>& nums, int k) {
        
        vector<int>ones;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                ones.push_back(i);
        }
        for(int i=0;i<ones.size();i++)
            ones[i] = ones[i] - i;
        /*for(int i=0;i<ones.size();i++)
            cout<<ones[i]<<" ";
        cout<<endl;*/
        
        
        int start = 0;
        int end = start+k-1;
        int mid = start + (k+1)/2 - 1;
        
        int left_size = mid-start;
        int right_size = end-mid;
        
        int left_sum=0, right_sum=0;
        int ans = INT_MAX;
    
        while(end<ones.size())
        {
            //cout<<start<<" "<<mid<<" "<<end<<endl;
            if(start==0)
            {
                // Calculate answer for the window for the first time.
                for(int i=start;i<mid;i++)
                    left_sum+=(ones[mid]-ones[i]);
                for(int i=mid+1;i<=end;i++)
                    right_sum+=(ones[i]-ones[mid]);
                ans = min(ans, left_sum+right_sum);
                
                
            }
            else
            {
                int prev_mid = mid-1;
                int prev_start = start-1;
                left_sum = left_sum - (ones[prev_mid] - ones[prev_start]) + (left_size*(ones[mid]-ones[prev_mid]));
                right_sum = right_sum + (ones[end] - ones[mid]) - (right_size*(ones[mid]-ones[prev_mid]));
                ans = min(ans, left_sum+right_sum);
            }
            start++;
            end++;
            mid++;
        }
        return ans;
    }
};