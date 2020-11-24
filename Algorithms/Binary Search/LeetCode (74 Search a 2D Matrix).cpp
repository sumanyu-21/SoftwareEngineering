class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0)
            return false;
        //cout<<matrix.size()<<endl;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int left = 0;
        int right = rows;
        while(left<right) // T T T T T F F F F 
        {                
            int mid = left + (right-left)/2;
            
            if(mid!= rows && matrix[mid][0]>target)
                right = mid;
            else
                left = mid+1;
        }
        cout<<left<<endl;
        /*if(left==rows)
            return false;*/
       
        int row_pos = left-1;
        if(row_pos<0)
            return false;
        left = 0, right = cols-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(matrix[row_pos][mid]==target)
                return true;

            matrix[row_pos][mid]>target?right--:left++;
        }
        return false;
        
        
    }
};