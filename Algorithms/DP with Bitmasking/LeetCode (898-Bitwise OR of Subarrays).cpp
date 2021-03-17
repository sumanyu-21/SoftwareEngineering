/*class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        
        int n = arr.size();
        vector<vector<int>>next_occurence(n+1, vector<int>(30,n));
         
        for(int i=n-1;i>=0;i--)
        {
            for(int bit=0;bit<30;bit++)
            {
                next_occurence[i][bit] = next_occurence[i+1][bit];
                if(arr[i]&(1<<bit))
                    next_occurence[i][bit] = i;
            }
        }
        //cout<<"here"<<endl;
        set<int>values;
        for(int i=0;i<n;i++)
        {
            vector<pair<int,int>>pairs;
            for(int bit=0;bit<30;bit++)
                pairs.push_back({next_occurence[i][bit],bit});
            
            sort(pairs.begin(),pairs.end());
            if(arr[i]==0)
                values.insert(0); // Edge Case:when arr[i]==0, we will enter for loop but next_occurence[i] is n for all bits and hence break out of the loop. Hence we add 0 directly.
            
            int or_so_far = 0;
            for(int j=0;j<pairs.size();j++)
            {
                if(pairs[j].first==n)
                    break;
                or_so_far|=(1<<pairs[j].second);
                while(j<pairs.size()-1 && pairs[j].first==pairs[j+1].first)
                {
                    or_so_far|=(1<<pairs[++j].second);
                }
                values.insert(or_so_far);
            }
        }
        return values.size();   
    }
};*/

class Solution
{
    public:
    int subarrayBitwiseORs(vector<int>& arr) {
        vector<set<int>>s(arr.size());
        s[0].insert(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            for(int x:s[i-1])
                s[i].insert(x|arr[i]);
            s[i].insert(arr[i]);
        }
        set<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            for(int x:s[i])
                ans.insert(x);
        }
        return ans.size();
    }
};