# include <iostream>
# include <bits/stdc++.h>
using namespace std;
# define long long long

class Sol
{
    public:
    int x; // Starting location of the very last interval
    long prev_cost; // Best cost so far for points upto x-1;
    int C;

    Sol()
    {
        this->x = 0;
        this->prev_cost = 0;
        this->C = 0;
    }

    Sol(int x, long prev_cost, int C)
    {
        this->x = x;
        this->prev_cost = prev_cost;
        this->C = C;
    }

    long getCost(long y)
    {
        // Cost if we end this interval at y.
        long d = (x-y);
        return prev_cost + d*d + C;
    }
    // Time when rhs overtakes this
    long to(Sol rhs)
    {
        long lo = rhs.x;
        long hi = rhs.x; // We don't know exact value of high. We can't use max because may cause overflow.
        // We are going to keep doubling our high until rhs overtakes this curve.
        while(getCost(hi)<rhs.getCost(hi))
        {
            lo = hi+1;
            hi*=2;
        }// Basically this code gives us what will be the upper bound for x

        // Now we can do our typical binary search.
        while(lo<hi)
        {
            long mid  = lo + (hi-lo)/2;
            if(getCost(mid)>=rhs.getCost(mid))
                hi = mid;
            else
                lo = mid+1;
        }
        return lo;
    }
};

int main()
{
    int N, C;
    cin>>N>>C;

    long bestPrev = 0; // Best covering before me.
    //vector<Sol> bag; // Keeping track of partial solutions.

    vector<Sol>dq(N);
    int fptr = 0; // In this case, we only need to take things out from the front and not push things from the front;
    int bptr = 0; // We can push from back as well as remove from back.

    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x; // Read X;
        Sol partial(x, bestPrev, C);
        
        /** Variant 
         * Make sure, we have atleast three things in bag.
         * Update bestPrev using every
         */
         
        while(bptr-fptr>=2 && dq[bptr-2].to(dq[bptr-1])>=dq[bptr-2].to(partial)) /
            bptr--;
        dq[bptr++] = partial;
        
        while(fptr+1<bptr && dq[fptr].getCost(x)>=dq[fptr+1].getCost(x))
            fptr++;

        bestPrev = dq[fptr].getCost(x);
        
    }
    cout<<bestPrev;
    return 0;

}
