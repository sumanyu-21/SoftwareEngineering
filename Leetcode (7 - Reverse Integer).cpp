/*class Solution {
public:
    int reverse(int x) {
        string s = to_string(abs((long long)x)); // Taking absolute may cause overflow.
        cout<<s<<endl;
        std::reverse(s.begin(),s.end());
        long long ans= (x<0?-1 :1) * stoll(s);
        if(ans>INT_MAX || ans <INT_MIN)
            return 0;
        return ans;
        
    }
};*/

class Solution{
    public:
    int reverse(int x)
    {
        long long ans = 0;
        
        //long long x = abs((long long)y); // Don't need to do this. Works without this
        while(x)
        {
            int last_digit = x%10;
            ans = ans*10 + last_digit;
            x/=10;
        }
        //ans = (y>0)?ans:-ans;
        if(ans<INT_MIN || ans>INT_MAX)
            return 0;
        return ans;
    }
};