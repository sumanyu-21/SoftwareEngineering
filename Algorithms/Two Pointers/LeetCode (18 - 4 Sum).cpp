//vector<vector<int>>ans;
/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;

        for(int i=0; i<=n-4;i++)
        {
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<=n-3;j++)
            {
                if(j!= (i+1) && nums[j]==nums[j-1])
                    continue;
                int partial_sum = nums[i]+nums[j];
                
                int start = j+1;
                int end = n-1;

                while(start<end)
                {
                    while(end-1>start && nums[start]+nums[end]+partial_sum>target)
                        end--;
                    if(nums[start]+nums[end]+partial_sum==target)
                        ans.push_back({nums[i],nums[j],nums[start],nums[end]});

                    start++;
                    while(start<n && nums[start]==nums[start-1])
                        start++;
                }
            }
        }
        return ans;
        
    }
};
*/
int n;
int target;
vector<int>nums;
vector<vector<int>>ans;

void twoSum(int start, int sum, vector<int>&included)
{
    //cout<<target<<endl;
    int end = n-1;
    int to_find = target-sum;
    while(start<end)
    {
        vector<int>temp = included;
        while(end-1>start && nums[start]+nums[end]+sum > target)
            end--;
        if(nums[start]+nums[end]+sum==target)
        {
            temp.push_back(nums[start]);
            temp.push_back(nums[end]);
            ans.push_back(temp);
        }
        start++;
        while(start<n && nums[start]==nums[start-1])
            start++;

    }
}

void kSum(int i, int k, int sum, vector<int>included)
{
    if(i<=n-1 && nums[i]*k+sum>target || nums.back()*k+sum<target)
        return;
    if(k==2)
    {
        if((n-1)-i+1>=2) // Atleast 2 elements should be remaining to find the 2Sum.
        {
        // We have two sum problem;
            //int size1 = included.size();
            twoSum(i,sum, included); // Will find the pair 
            /*if(included.size()-size1==2)
                ans.push_back(included);*/
        }
        else
            return;
    }
    for(int j=i;j<n;j++)
    {
        if(j!=i && nums[j]==nums[j-1])
            continue;
        vector<int>arr = included;
        arr.push_back(nums[j]);
        kSum(j+1, k-1, sum+nums[j], arr); // Include this element and consider rest of the array.
        
    }

    return;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& numss, int t) {
        n = numss.size();
        cout<<n<<endl;
        nums = numss;
        target = t;
        sort(nums.begin(), nums.end());
        //vector<vector<int>>ans;
        vector<int>included;
        included.reserve(4);
        //vector<vector<int>>ans;
        ans.clear();
        ans.reserve(100000);
        if(n<4)
            return ans;
        kSum(0,4,0,included);
        return ans;

    }

};
