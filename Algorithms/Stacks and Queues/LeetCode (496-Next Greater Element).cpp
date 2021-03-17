class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>exists;
        for(int i=0;i<nums1.size();i++)
            exists[nums1[i]]+=1;
        
        stack<int>s;
        s.push(nums2[0]);
        unordered_map<int,int>ans;
        for(int i=1;i<nums2.size();i++)
        {
            if(nums2[i]<nums2[i-1])
                s.push(nums2[i]);
            else
            {

                while(!s.empty() && nums2[i]>s.top())
                {
                    //cout<<"gere"<<endl;
                    if(exists.find(s.top())!=exists.end())
                    {
                        //cout<<"here"<<endl;
                        ans[s.top()]= nums2[i];
                    }
                   // cout<<s.top()<<endl;
                    s.pop();
                }
                s.push(nums2[i]);
                //cout<<s.top()<<endl;
            }
        }
        //cout<<"herrrre"<<endl;
        while(!s.empty())
        {
            if(exists.find(s.top())!=exists.end())
                ans[s.top()] = -1;
            s.pop();
        }
        vector<int>final_ans;
        final_ans.resize(nums1.size());
        for(int i=0;i<nums1.size();i++)
            final_ans[i] = ans[nums1[i]];
        
        return final_ans;
    }
};