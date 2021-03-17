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
};

void test_case()
{
    P p1, p2, p3;
    p1.read(), p2.read(), p3.read(); //We could have read in constructor as well.
    //p3 = p3-p1;
    //p2 = p2-p1;
    p3-=p1;
    p2-=p1;
    long long cp = p2*p3;
    if(cp<0)
    {
        //P2 on the left from P3;
        cout<<"RIGHT"<<endl;
    }
    else if(cp>0)
    {
        cout<<"LEFT"<<"\n";
    }
    else
        cout<<"TOUCH"<<"\n";
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        test_case();
    }
}
