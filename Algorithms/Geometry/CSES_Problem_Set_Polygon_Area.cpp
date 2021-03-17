# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;


struct P{
    long long x,y;
    void read()
    {
        cin>>x>>y;
    }

    P operator - (const P& b)const // Passing by refrence and passing as constant so that we dont change the value of b.
    {
        return P{x-b.x, y-b.y}; // Default constructor.
    }

    void operator -=(const P&  b)
    {
        x-=b.x;
        y-=b.y;
    }

    long long operator *(const P& b)const// const outside tells us that we don't want to modify our own value.
    {
        return x*b.y - y*b.x;
    }

    long long triangle(const P&b, const P&c)const{
        // With respect to me, compute cross product of b and c.
        return (b-*this) * (c-*this);
    }
};

void test_case()
{
   int n;
   cin>>n;
   vector<P>polygon(n);
   for(P& p: polygon)
       p.read();

    long long area = 0;
    for(int i=0;i<n;i++)
    {
        // FOr every 2 consecutive points.
        area+=polygon[i]*polygon[(i+1)%n];
    }
    cout<<abs(area)<<endl;
}

int main()
{
    int T;
    T=1;
    while(T--)
    {
        test_case();
    }
}
