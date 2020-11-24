/*class Solution {
    
    int search(int &target, vector<vector<int>>& matrix, int x1, int y1, int x2, int y2)
    {
        if(x1>x2 || y1>y2)
            return false;
        
        int midx = (x1+x2)/2 , midy = (y1+y2)/2;
        
        if(matrix[midx][midy]==target)
            return true;
        if(matrix[midx][midy]>target)
        {
            bool a = search(target, matrix, x1, y1, midx-1,midy);
            if(a==true)
                return true;
    
            bool b = search(target, matrix, midx, y1, x2, midy-1);
             if(b==true)
                return true;
            bool c = search(target, matrix, x1, midy+1, midx-1, y2);
            if(c==true)
                return true;
            return false;
            return a||b||c;
        }
        else
        {
            bool a = search(target, matrix, midx+1, y1, x2, midy);
            if(a==true)
                return true;
            bool b = search(target, matrix, midx, midy+1, x2, y2);
            if(b==true)
                return true;
            bool c = search(target, matrix, x1, midy+1, midx-1, y2);
            if(c==true)
                return true;
            return a||b||c;
        }
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //cout<<matrix.size()
        if(matrix.size()==0)
            return 0;
        return search(target, matrix, 0, 0, matrix.size()-1, matrix[0].size()-1);
        
    }
};*/

// Another efficient Solution O(rows + cols)
class Solution{
    public:
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int rows = matrix.size();
         if(rows==0)
             return 0;
         int cols = matrix[0].size();
         
         int r = 0, c = cols-1;
         while(r<rows && c>=0)
         {
             if(matrix[r][c]==target)
                 return true;
             target>matrix[r][c]?r++:c--;
         }
         return false;
     }
};