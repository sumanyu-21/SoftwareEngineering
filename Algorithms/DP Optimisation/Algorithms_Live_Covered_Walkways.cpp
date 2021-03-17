# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Sol
{
    public:
    int x; // Starting location of the very last interval
    long prev_cost; // Best cost so far for points upto x-1;
    int C;

    Sol(int x, long prev_cost, int C)
    {
        this->x = x;
        this->prev_cost = prev_cost;
        this->C = C;
    }

    long getCost(int y)
    {
        // Cost if we end this interval at y.
        long d = (x-y);
        return prev_cost + d*d + C;
    }
};

int main()
{
    int N, C;
    cin>>N>>C;

    long bestPrev = 0; // Best covering before me.
    vector<Sol> bag; // Keeping track of partial solutions.

    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x; // Read X;
        Sol partial(x, bestPrev, C);
        bag.push_back(partial);
        // Update bestPrev using every
        bestPrev = LONG_MAX;
        for(Sol p:bag)
            bestPrev = min(bestPrev, p.getCost(x));
    }
    cout<<bestPrev;
    return 0;

}
