class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        stack<int>s;
        s.push(0);
        vector<int>ans(a.size(),0);
        for(int i=1;i<a.size();i++)
        {
            if(a[i]<a[s.top()])
                s.push(i);
            
            else
            {
                while(!s.empty() && a[i]>a[s.top()])
                {
                    ans[s.top()] = i-s.top();
                    s.pop();
                }
                s.push(i);
            }
        }
        return ans;
        
    }
};