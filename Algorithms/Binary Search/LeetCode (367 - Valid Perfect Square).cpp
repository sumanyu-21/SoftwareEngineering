class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        if(num==1)
            return true;
        while(left<right)
        {
            long mid = left + (right - left)/2;
        
            if(mid*mid==num)
                return true;
            if(mid*mid<num)
                left = mid+1;
            else
                right = mid;
        }
        return false;
        
    }
};