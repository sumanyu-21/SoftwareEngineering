/*class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>min_array(nums.size());
        vector<int>max_array(nums.size());
        int n = nums.size();
        
        for(int i=0;i<nums.size();i++)
            min_array[i] = i==0?nums[i]:min(min_array[i-1],nums[i]);
        
        for(int i=nums.size()-1;i>=0;i--)
            max_array[i] = i==n-1?nums[i]:max(max_array[i+1], nums[i]);
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!= min_array[i] && nums[i]!= max_array[i] && min_array[i]!=max_array[i])
                return true;
            
        }
        return false;
    }
};*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int arr[3];
        arr[0] = nums[0];
        int LIS_SIZE = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>arr[LIS_SIZE-1])
            {
                arr[LIS_SIZE] = nums[i];
                LIS_SIZE++;
                if(LIS_SIZE==3)
                    return true;
            }
            else
            {
                for(int j=0;j<LIS_SIZE;j++)
                {
                    if(arr[j]>=nums[i])
                    {
                        arr[j] = nums[i];
                        break;
                    }
                }
            }
            //cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
        }
        return false;
    }
};