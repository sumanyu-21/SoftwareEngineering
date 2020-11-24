class Solution {
public:
    double myPow(double x, long n) {
        double ans = 1.0;
        //bool pos = n>=0?true:false;
        if(n<0)
            x = (1.0)/x;
        n = abs(n);
        while(n>0)
        {
            cout<<ans;
            if(n&1)
                ans = ans * x;
            
            cout<<x<<endl;
            x*=x;
            n>>=1;
        }
        /*if(!pos)
        {
            //cout<<ans<<endl;
            ans = 1.0/ans;
            
        }*/
        
        return ans;
    }
};