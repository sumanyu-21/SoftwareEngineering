/*class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]+=1;
            if(m[nums[i]]>1)
                return nums[i];
        }
      
        return 0;
    }
};*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int p1 =0, p2 = 0;
        //cout<<p1<<" "<<p2<<endl;
        p1 = nums[p1], p2 = nums[nums[p2]];
        while(nums[p1]!=nums[p2])
        {
            p1 = nums[p1];
            p2 = nums[nums[p2]];
        }
        cout<<nums[p1]<<" "<<nums[p2]<<endl;
        p1 = 0;
        while(nums[p1]!=nums[p2])
        {
            p1 = nums[p1];
            p2 = nums[p2];
        }
        return nums[p2];
    }
};
    