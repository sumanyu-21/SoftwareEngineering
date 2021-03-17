class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        stack<int>s;
        int max_so_far = -1;
        vector<int>ans(arr.size(),-1);
        for(int i=arr.size()-1;i>=0;i--)
        {
            ans[i] = max_so_far;
            max_so_far = max(max_so_far, arr[i]);
        }
        return ans;
    }
};