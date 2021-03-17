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

    void operator -=(const P &b)
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

     //Without this operator, we don't need the sort function.
    bool operator <(const P&b) const{
        return make_pair(x,y) < make_pair(b.x,b.y);
    }

    /*bool operator <(const P&b)const{
        return *this*b<0;  // This is on the left of of b. This means this appears first when we move in clockwise 
        //direction with point 0,0 as refrence.
    }*/
};

// Using Graham Scan Algorithm

void sort_by_distance(vector<P>&points)
{
    //sort_by_distance(points);
    sort(points.begin(),points.end()); // Sort from left to right.

    vector<P>hull;
    for(int rep=0;rep<2;rep++)
    {
        int S = hull.size();
        for(P C:points)
        {
            while((int)hull.size()-S>=2){
                P A = hull.end()[-2];
                P B = hull.end()[-1];

                if(A.triangle(B,C) <= 0) // B on the left side of  A. If(we allow 0, as well, then we allow collinear points on convex hull)
                {// Good, don't do anything.
                    break;
                }
                hull.pop_back();
            }
            hull.push_back(C);
        }
        // We have the top part of the hull.
        reverse(points.begin(), points.end());
        hull.pop_back(); // Remove the rightmost point, otherwise it will be considered twice.
        //cout<<hull.size()<<endl;
    }
    cout<<hull.size()<<endl;
    for(int i=0;i<(int)hull.size();i++)
    {
        cout<<hull[i].x<<" "<<hull[i].y<<endl;
    }
    return;
}

void sort_by_angle(vector<P>& points)
{
    int n = points.size();
    // making 0th point as origin.
    for(int i=1;i<n;i++)
        points[i]-=points[0];

    sort(points.begin()+1, points.end()); // Everything other than the first point should be implemented.
    
    vector<P>hull;
    hull.push_back(P{0,0});
    for(int i=1;i<n;i++)
    {
        P C=points[i];
        while((int)hull.size()>=2){
            P A = hull.end()[-2];
            P B = hull.end()[-1];

            if(A.triangle(B,C) <= 0) // B on the left side of  A. If(we allow 0, as well, then we allow collinear points on convex hull)
            {// Good, don't do anything.
                break;
            }
            hull.pop_back();
        }
        hull.push_back(C);
    }
    cout<<hull.size()<<endl;
    for(int i=0;i<(int)hull.size();i++)
    {
        cout<<hull[i].x+points[0].x<<" "<<hull[i].y+points[0].y<<endl;
    }
    return;
}


int main()
{
    int n;
    cin>>n;
    vector<P> points(n);
    for(int i=0;i<n;i++)
        points[i].read();

    
    sort_by_distance(points);
    //sort_by_angle(points);  Doesn't give correct answer for collinear points.

    
    
}