class Solution {
public:
    
    vector<int> get(vector<int>&nums, int K)
    {
        if(K==0)
            return {};
        vector<int>next_biggest(nums.size(),-1);
        stack<int>ss;
        ss.push(0);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[ss.top()])
                ss.push(i);
            
            else
            {
                while(!ss.empty() && nums[ss.top()]<nums[i])
                {
                    next_biggest[ss.top()] = i;
                    ss.pop();  
                }
                ss.push(i);
            }  
        } 
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(ans.size()==K)
                return ans;
            
            int idx = next_biggest[i];
            if(idx!=-1 && nums.size()-1-idx+1>=K-ans.size())
                continue;
            else
                ans.push_back(nums[i]);
            
        }
        return ans;
    }
    
    
    vector<int>merge(vector<int>&nums1, vector<int>&nums2, int k)
    {
        vector<int>ans(k);
        for(int i=0,j=0,r=0;r<k;r++)
        {
            ans[r] = greater(nums1,i, nums2, j)?nums1[i++]:nums2[j++];
        }
        return ans;
    }
    
    
    bool greater(vector<int>&nums1, int i, vector<int>&nums2, int j)
    {
        while(i<nums1.size() && j<nums2.size() && nums1[i]==nums2[j])
        {
            i++;
            j++;
        }
        return j==nums2.size() || (i<nums1.size() && nums1[i]>nums2[j]);
    }
    
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<int>final_answer(k,0);
        for(int k1=0;k1<=k;k1++)
        {
            
            if(k1>nums1.size() || k-k1>nums2.size())
                continue;
            
            vector<int>arr1 = get(nums1, k1);
            vector<int>arr2 = get(nums2,k-k1);
            
            for(int i=0;i<arr1.size();i++)
                cout<<arr1[i]<<" ";
            cout<<endl;
            
            for(int i=0;i<arr2.size();i++)
                cout<<arr2[i]<<" ";
            cout<<endl;
            vector<int>a = merge(arr1, arr2, k);
            int z = 0;
            while(z<k && a[z]==final_answer[z])
                z++;
            if(z!=a.size() && final_answer[z]<a[z])
                final_answer = a;
            
        }
        return final_answer;
    }
};