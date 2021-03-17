# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

class Node
{
	int x;
	int l;
	int r;
}

class SegmentTree
{
	int n;
	vector<Node>s_t;
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
		// The answers from 2 segments can be merged.
		if(s_t[2*i+1].r== s_t[2*i+2].l)
		{}
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