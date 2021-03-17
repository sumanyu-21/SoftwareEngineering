class Solution {
public:
    vector<int>BIT;
	vector<int>arr;
    unordered_map<int, int>my_map;
    int n;
    void mapping()
    {
        for (int i = 0; i < n; i++)
        {
            if (my_map.find(arr[i]) == my_map.end())
                my_map[arr[i]] = i + 1;
        }
	}
    
    
    void Fenwick(vector<int>&nums)
    {
        BIT.resize(n + 1, 0);
        arr = nums;

        sort(arr.begin(), arr.end());
        mapping();
    }
    
    void update(int i,int val)
    {
        while (i <= n)
        {
            BIT[i] += val;
            i += i & (-i);
        }
    }

    int query(int i)
    {
        int ans = 0;
        while (i > 0)
        {
            ans += BIT[i];
            i -= i & (-i);
        }
        return ans;
    }
    
    
    vector<int> countSmaller(vector<int>& nums) 
    {
        n = nums.size();
        vector<int>ans(n, 0);
        
        Fenwick(nums);
        for (int i = n-1; i>=0; i--)
        {
            update(my_map[nums[i]],1);
            ans[i] = query(my_map[nums[i]]-1);
        }
        return ans;
    }
    
};