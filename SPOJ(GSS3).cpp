# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
	int n;
	vector<int>s_t;
	vector<int>low,high;
public:
	SegmentTree(int n)
	{
		SegmentTree::n = n;
		s_t.resize(4*n+1);
		low.resize(4*n+1);
		high.resize(4*n+1);
		init(0,0,n-1);
	}

	void update(int i)
	{
		int x = s_t[2*i+1];
		int y = s_t[2*i+2];

		s_t[i] = max(x+y,max(x,y));
	}

	void update_range(int i, int a, int val)
	{
		// No Overlap
		if(a<low[i] || high[i]<a)
			return;

		if(a==low[i] && a==high[i])
		{
			s_t[i] = val;
			return;
		}

		update_range(2*i+1, a, val);
		update_range(2*i+2, a, val);
		update(i);
		return ;

	}

	int query_range(int i, int a, int b)
	{
		// No overlap;
		if(b<low[i] || high[i]<a)
			return INT_MIN;

	 	// Complete Overlap
	 	if(a<=low[i] && high[i] <=b)
	 		return s_t[i];

        //cout<<i<<" "<<x<<" "<<y<<" "<<s_t[i]<<endl;
	 	//cout<<a<<" "<<b<<" "<<low[i]<<" "<<high[i]<<endl;
	 	int x = query_range(2*i+1, a, b);
	 	//cout<<i<<" "<<s_t[2*i+1]<<" "<<x<<endl;
	 	int y = query_range(2*i+2, a, b);
	 	//cout<<y<<endl;
	 	update(i);
	 	//cout<<i<<" "<<x<<" "<<y<<endl;

	 	if(y==INT_MIN)
            return x;
        else if(x==INT_MIN)
            return y;
        else
            return x+y;
	}

	void init(int i, int a, int b)
	{
	    low[i] = a;
	    high[i] = b;
	    if(a==b)
            return;
        int mid = (a+b)/2;
        init(2*i+1, a, mid);
        init(2*i+2, mid+1, b);
        return;
	}

	void print()
	{
	    for(int i=0;i<7;i++)
            cout<<s_t[i]<<" "<<low[i]<<" "<<high[i]<<endl;
        cout<<endl;
	}
};

int main()
{
	int n;
	cin>>n;
	SegmentTree ob(n);
	for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        ob.update_range(0,i,val);
        //ob.print();
    }

	int m;
	cin>>m;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1)
			cout<<ob.query_range(0,b-1,c-1);
		else
			ob.update_range(0,b-1,c);

        //ob.print();

	}
}
