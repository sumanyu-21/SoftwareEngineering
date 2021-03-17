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

bool segmentIntersection(P p1, P p2, P p3, P p4)
{
    
    // Parallel Case:
    if((p2-p1) * (p4-p3)==0)
    {
        // 2 segments are parallel.
        //(1) Considering the case when they are collinear
        if(p1.triangle(p2,p3)!=0)
        {
            // P3 is not collinear with P1 and P2.
            return false;
        } 

        // (2) Check if 2 bounding boxes intersect. Check if 2 rectangles intersect.
        for(int rep=0;rep<2;rep++)
        {
            if(max(p1.x, p2.x) < min(p3.x, p4.x) ||  max(p1.y, p2.y) < min(p3.y, p4.y))
            {
                return false;
            }
            // Swap the 2 segments;
            swap(p1, p3);
            swap(p2,p4);

        }
        return true;
    }

    for(int rep=0;rep<2;rep++)
    {
        long long sign1 = (p2-p1) * (p3-p1);
        long long sign2 = (p2-p1) * (p4-p1);
        if((sign1<0 && sign2<0) ||(sign1>0 && sign2>0))
        {
            // Segment B is completely on left or right of "LINE" A.
            return false;
        }
        // Swap the 2 segments;
        swap(p1,p3);
        swap(p2,p4);
    }
    return true;
}

bool segment_contains(P a, P b, P c)
{
     if(a.triangle(b,c)!=0)
        return false; // Not collinear;
    
    return min(a.x,b.x)<= c.x && c.x<= max(a.x, b.x) &&
            min(a.y, b.y)<=c.y &&c.y<=max(a.y,b.y);
    

}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<P>polygon(n);
    for(P&p:polygon)
        p.read();

    for(int rep=0;rep<m;rep++)
    {
        P p;
        p.read();
        P out = P{p.x+1, 3'000'000'001LL};
        
        bool is_on_boundary = false; 
        int count=0;
        for(int i=0;i<n;i++)
        {
            int j = (i+1)%n;
            if(segment_contains(polygon[i], polygon[j], p))
            {
                is_on_boundary = true;
                break;
            }
            if(segmentIntersection(p, out, polygon[i], polygon[j]))
                count++;
        }
        if(is_on_boundary)
            cout<<"BOUNDARY\n";
        else if(count % 2==0)
            cout<<"OUTSIDE\n";
        else
            cout<<"INSIDE\n";
    }


}
