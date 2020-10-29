# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
	int n;
	vector<int>low, high, d_t, s_t;

public:
	SegmentTree(int n)
	{
		SegmentTree::n = n;
		low.resize(4*n+1);
		high.resize(4*n+1);
		d_t.resize(4*n+1);
		s_t.resize(4*n+1, 0);
		init(0,0,n-1);
	}

	void update(int i, int type)
	{
	    if(type==0)
            s_t[i] = s_t[2*i+1] | s_t[2*i+2];
        else
            s_t[i] = s_t[2*i+1] ^ s_t[2*i+2];
	}

	pair<int,int> update_range(int i, int a,  int val)
	{
	    if(low[i]==a && high[i]==a)
        {
            s_t[i] = val;
            //cout<<i<<" "<<s_t[i]<<"----"<<endl;
            return make_pair(s_t[i], 0);
        }

        if(a<low[i] || high[i]<a)
            return make_pair(0,-1);

        pair<int,int>x = update_range(2*i+1, a, val);
        pair<int,int>y = update_range(2*i+2, a, val);

        int type;
        if(x.second==-1)
            type = y.second;
        else if(y.second==-1)
            type = x.second;

        else
            type =x.second;

        update(i, type);
        return make_pair(s_t[i], (type+1)%2);

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
            cout<<low[i]<<" "<<high[i]<<endl;

	    for(int i=0;i<7;i++)
            cout<<s_t[i]<<" ";
        cout<<endl;
	}


};

using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int N = (1<<n);
	SegmentTree ob(N);
	//ob.print();
	for(int i=0;i<(1<<n);i++)
	{
		int x;
		cin>>x;
		pair<int,int>p = ob.update_range(0,i,x);
		//cout<<p.first<<" "<<p.second<<endl;
		//ob.print();
	}
	while(m--)
	{
		int a, val;
		cin>>a>>val;
		pair<int,int>ans = ob.update_range(0,a-1,val);
		cout<<ans.first<<endl;
	}

}
