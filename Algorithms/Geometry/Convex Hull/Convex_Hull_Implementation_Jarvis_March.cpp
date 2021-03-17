# include<iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

class Cpoint
{
public:
    long long x,y,z;
    Cpoint(long long x=0, long long y =0, long long z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Cpoint operator+(Cpoint b)
    {
        return Cpoint(this->x+b.x, this->y+b.y, this->z+b.z);
    }
    Cpoint operator-(Cpoint b)
    {
        return Cpoint(this->x-b.x, this->y-b.y, this->z-b.z);
    }
    Cpoint operator*(long long val)
    {
        return Cpoint(this->x*val, this->y*val, this->z*val);
    }
    Cpoint operator/(long long val)
    {
        return Cpoint(this->x/val, this->y/val, this->z/val);
    }

    Cpoint& operator=(Cpoint b)
    {
        this->x=b.x;
        this->y=b.y;
        this->x=b.z;
        return *this;
    }
    Cpoint& operator-=(Cpoint b)
    {
        *this=*this-b;
        return *this;
    }
    Cpoint& operator*=(long long val)
    {
        (*this)=(*this)*val;
        return *this;
    }
    Cpoint& operator/=(long long val)
    {
        (*this)=(*this)/val;
        return *this;
    }
 
    bool operator==(Cpoint b)
    {
        if(this->x==b.x && this->y==b.y && this->z==b.z) return true;
        else return false;
    }
};

long long dot(Cpoint a,Cpoint b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

Cpoint cross(Cpoint a,Cpoint b)
{
    return Cpoint(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x );
}

long long signed_area_of_parallelogram(Cpoint a,Cpoint b,Cpoint c)
{
    return cross(b-a,c-b).z;
}

int direction(Cpoint a,Cpoint b,Cpoint c)
{
    long long t=signed_area_of_parallelogram(a,b,c);
 
    if(t<0) return -1;
    else if(t>0) return 1;
    else return 0;
}



vector<Cpoint> convex_hull_jarvis_march(vector<Cpoint> a)
{
    int n = a.size();
    int strt = 0;
    for(int i=1;i<n;i++)
    {
        if(a[i].x < a[strt].x || (a[i].x == a[strt].x && a[i].y < a[strt].y))
            strt = i;
    }

    vector<Cpoint>ans;
    ans.push_back(a[strt]);

    while(true)
    {
        int pt = 0;  // Candidate for next point in convex hull. Now we try to find if we can find a better candidate for the convex hull
                     // More clockwise angle.
        for(int i=0;i<n;i++)
        {
            if(a[i] == ans.back()) continue;

            /* (If clockwise angle of current point is greater than the candidate point) ||
               (If the current point is farther than the candidtae point)
            */
            if((direction(ans.back(), a[pt], a[i]) == -1) ||
                (direction(ans.back(), a[pt], a[i]) == 0 &&
                dot(a[i] - ans.back(), a[i] - ans.back()) > dot(a[pt] - ans.back(), a[pt] - ans.back()) ) )
            {
                pt = i;// Update the candidtae point.
            }
        }

        if(a[pt] == ans.front()) break;
        else ans.push_back(a[pt]);      
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<Cpoint> a(n);
 
    for(int i=0;i<n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
 
    a=convex_hull_jarvis_march(a);
 
    for(auto it:a) cout<<it.x<<' '<<it.y<<'\n';
 
 
    return 0;
}
