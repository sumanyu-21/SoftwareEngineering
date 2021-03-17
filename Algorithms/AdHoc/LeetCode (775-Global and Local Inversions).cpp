class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        vector<int>max_arr(n);
        if(n==1 || n==2)
            return true;
        max_arr[0] = A[0];
        max_arr[1] = max(A[0],A[1]);
        int flag = 0;
        for(int i=2;i<n;i++)
        {
            if(A[i]>=max_arr[i-2])
                max_arr[i] = max(A[i],max_arr[i-1]);
        
            else
            {
                flag = -1;
                break;
            }
        }
        if(flag ==0)
            return true;
        else
            return false;
        
    }
};