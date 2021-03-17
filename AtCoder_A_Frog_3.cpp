# include <iostream>
# include <stdio.h>
# include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define setIO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
# define int long long
class CHT
{
   public:

    class Line
    {
        int slope, yIntercept;
        public:
        //int slope, yIntercept;
        Line(int slope, int yIntercept) : slope(slope), yIntercept(yIntercept){}

        int val(int x)
        {
            return slope*x + yIntercept;
        }
        //a/b--->(a+b-1)/b; to take ceiling.
        int intersect(Line y)
        {
            return (y.yIntercept - yIntercept + slope - y.slope - 1)/(slope - y.slope);
        }

    };

    deque<pair<Line,int>> dq;

    void insert(int slope, int yIntercept)
    {
        Line newLine(slope, yIntercept);

        // Intersection of the new line with the last line.
        while(!dq.empty() && dq.back().second>=dq.back().first.intersect(newLine))
            dq.pop_back();

        if(dq.empty())
        {
            dq.emplace_back(newLine,0); // We don't have -ve values of x so 0 will work.
            return;
        }
        dq.push_back({newLine, dq.back().first.intersect(newLine)});
    }

    int query(int x)
    {
        while(dq.size()>1)
        {
            if(dq[1].second<=x) dq.pop_front();
            else break;
        }
        return dq[0].first.val(x);
    }

    int query2(int x)
    {
        auto qry = *lower_bound(dq.begin(),dq.end(),
                                make_pair(Line(0,0), x),
                                [&](const pair<Line,int> &a, const pair<Line,int>&b){
                                    return a.second<b.second;
                                });
        return qry.first.val(x);

    }
};

signed main()
{
    FAST_IO;

    int n,c;
    cin>>n>>c;
    vector<int>h(n,0);

    for(int i=0;i<n;i++) cin>>h[i];

    CHT cht;
    vector<int>dp(n,0);
    dp[0] = 0;
    cht.insert(-2*h[0], h[0]*h[0] + dp[0]);

    for(int i=1;i<n;i++)
    {
        dp[i] = cht.query(h[i]) +c + h[i]*h[i];
        cht.insert(-2*h[i], h[i]*h[i] +dp[i]);
    }
    cout<<dp[n-1];

}