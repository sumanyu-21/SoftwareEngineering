class Solution {
public:
    int mySqrt(long x) {
        // T T T T F F F F
        long i = 0, j = x+1; // (x+1 is done in case all are True  T T T T)
        /*if(x==0)
            return 0;*/
        while(i<j)
        {
            long mid = (i+j)/2;
            cout<<i<<" "<<j<<" "<<mid<<endl;
            if(!(mid*mid<=x)) // If not property
                j = mid;
            else
                i = mid + 1;
        }
        return j-1;
    }
};