const int MOD = 1e9+7;
/*class Solution {
public:
    
    int binary_search1(int i, int strt, int end, int to_find, vector<int>& prefix)
    {
        int left = strt, right = end+1;
        while(left<right)//F F F F F T T T T
        {
            int mid = (left+right)/2;
            if(prefix[mid]-prefix[i]>=to_find)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
    
    int binary_search2(int i, int strt, int end, int to_find, vector<int>&prefix)
    {
        int left = strt, right = end+1;
        while(left<right)// T T T T F F F F 
        {
            int mid = (left + right)/2;
            if(!(prefix.back()-prefix[mid]>=prefix[mid]-prefix[i]))
                right= mid;
            else
                left = mid+1;
        }
        return left-1;
    }
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++)
            prefix[i]=nums[i] + prefix[i-1];
        
        int ans = 0;
        for(int i=0;i<=n-3;i++)
        {
            int left_sum = prefix[i];
            int pos1 = binary_search1(i, i+1, n-2,left_sum, prefix);
            if(pos1==n-1)
                break;
            
            int pos2 = binary_search2(i,i+1, n-2, left_sum, prefix);
            if(pos2==i)
                break;
            
            if(pos2>=pos1)
            ans = (ans + pos2-pos1 +1)%MOD;
        }
       return ans; 
    }
};*/

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++)
            prefix[i] = prefix[i-1]+nums[i];
        
        int j=0,k=0;
        int ans = 0;
        for(int i=0;i<nums.size()-2;i++)
        {
            j = max(j,i+1);
            while(j<=nums.size()-2 && 2*prefix[i]>prefix[j])
                j++;
            
            k = max(k,j);
            //prefix[k]-prefix[i]<=prefix.back()-prefix[k]
            while(k<=nums.size()-2 && 2*prefix[k]<=prefix.back()+prefix[i])
                k++;

            ans = (ans + k-j)%MOD;
        }
        return ans;
    }
};