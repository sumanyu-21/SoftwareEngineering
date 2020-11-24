class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int i = 0, j = n-1;
        while(i<j)
        {           
            int trapped = min(height[i], height[j])*(j-i);
            //cout<<i<<" "<<j<<" "<<trapped<<endl;
            water = max(water, trapped);
            if(height[i]<=height[j])
                i++;
            else
                j--;
            
        }
        return water;
        
    }
};