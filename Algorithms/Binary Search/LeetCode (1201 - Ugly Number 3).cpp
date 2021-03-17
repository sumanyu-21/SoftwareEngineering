/*class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        vector<int>arr = {a,b,c};
        sort(arr.begin(), arr.end());
        vector<int>pointers(arr.size(),1);
        int count = 0;
        int ugly;
        while(count<n)
        {
            int x = pointers[0] * arr[0];
            int y = pointers[1] * arr[1];
            int z = pointers[2] * arr[2];
            
            if(x<=y && x<=z)
            {
                ugly = x;
                pointers[0]++;
                if(x==y)
                    pointers[1]++;
                if(x==z)
                    pointers[2]++;
            }
            else if(y<=z && y<=x)
            {
                ugly = y;
                pointers[1]++;
                if(y==z)
                    pointers[2]++;
                if(y==x)
                    pointers[0]++;
            }
            else if(z<=x && z<=y)
            {
                ugly = z;
                pointers[2]++;
                if(z==x)
                    pointers[0]++;
                if(z==y)
                    pointers[1]++;
            }
            count++;
        }
        return ugly;
        
    }
};*/
# define ll long
class Solution {
    ll gcd(ll a, ll b)
    {
        if(b==0)
            return a; 
        return gcd(b, a%b);
    }
    ll lcm(ll a, ll b)
    {
        return (a*b)/gcd(a,b);
    }
    bool check(long i, int n, int a, int b, int c)
    {
        ll div_a = i/a;//i%a==0?i/a:0;
        ll div_b = i/b;//i%b==0?i/b:0;
        ll div_c = i/c;//i%c==0?i/c:0;
        
        ll div_ab = i/lcm(a,b);//i%(a*b)==0?(i/a)/b:0;
        ll div_bc = i/lcm(b,c);//i%(b*c)==0?(i/b)/c:0;
        ll div_ca = i/lcm(c,a);//i%(c*a)==0?(i/c)/a:0;
        
        ll div_abc = i/lcm(lcm(a,b),c);//i%(a*b*c)==0?((i/a)/b)/c:0;
        
        ll ugly_count = div_a + div_b + div_c - (div_ab + div_bc + div_ca) + div_abc ;
        //cout<<i<<" "<<ugly_count<<endl;
        if(ugly_count>=n)
            return true;
        return false;
    }
    
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        //cout<<gcd(5,10);
        long left = 1, right = 2*1e9;
        while(left<right)  // F F F  F T T T T T
        {
            long mid = left + (right - left)/2;
            if(check(mid, n, a, b, c))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
       
};