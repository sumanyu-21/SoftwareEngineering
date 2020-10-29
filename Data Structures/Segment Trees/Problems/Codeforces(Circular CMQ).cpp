# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
# define ll long long
using namespace std;



class SegmentTree
{
	ll n;
	vector<ll>low;
	vector<ll>high;
	vector<ll>s_t;
	vector<ll>d_t;

public:
	SegmentTree(ll n)
	{
		SegmentTree::n = n;
		low.resize(4*n+1);
		high.resize(4*n+1);
		s_t.resize(4*n+1,0);
		d_t.resize(4*n+1,0);

		init(0,0,n-1);
		/*for(int i=0;i<4*n+1;i++)
            cout<<low[i]<<" "<<high[i]<<endl;*/
	}

	void prop(ll i)
	{
		d_t[2*i+1]+= d_t[i];
		d_t[2*i+2]+= d_t[i];

		d_t[i] = 0;
	}

	void update(ll i)
	{
		s_t[i] = min(s_t[2*i+1] + d_t[2*i+1], s_t[2*i+2] + d_t[2*i+2]);
	}

	void rangeUpdate(ll i, ll a, ll b, ll val)
	{
		// No overlap
		if(b<low[i] || high[i]<a)
			return;

		// Complete overlap
		if(a<=low[i] && high[i]<=b)
		{
			d_t[i] = d_t[i] + val;
			//s_t[i] = s_t[i] + val;
			return;
		}

		prop(i); // Propagate previous changes down to children.
		rangeUpdate(2*i+1, a, b, val);
		rangeUpdate(2*i+2, a, b, val);

		update(i); // After returning from children, update the current node.

	}
	ll rangeMinimum(ll i, ll a, ll b)
	{
	    //cout<<a<<"-->"<<b<<endl;
		if(b<low[i] || high[i]<a)
			return LLONG_MAX;

		// Complete overlap
		if(a<=low[i] && high[i] <=b)
        {
            //cout<<s_t[i]<<" "<<d_t[i]<<" "<<a<<" "<<b<<endl;
            return s_t[i] + d_t[i];
        }

		// Partial Overlap
		prop(i);
		ll minLeft = rangeMinimum(2*i+1, a, b);
		ll minRight = rangeMinimum(2*i+2, a, b);

		update(i);
		return min(minLeft, minRight);
	}

	void init(ll i, ll a, ll b)
	{
		low[i] = a;
		high[i] = b;

		if(a==b)
			return;

		ll mid = (a+b)/2;
		init(2*i+1, a, mid);
		init(2*i+2, mid+1, b);
		return;
	}
	void print()
	{
	    for(int i=0;i<4*n+1;i++)
            cout<<d_t[i]<<" "<<s_t[i]<<endl;
	}



};

int stoi(string &s)
{
	stringstream ob(s);
	int res;
	ob >> res;
	return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n;
	cin>>n;
	SegmentTree ob(n);
	for(int i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		ob.rangeUpdate(0,i,i,val);
		//ob.print();
	}



	int m;
	cin>>m;
	cin.get();  // cin.get reads a string with the whitespace.
	while(m--)
	{
		string s;
		getline(cin, s);
		//cout<<s<<endl;
		stringstream ss(s);// Used for breaking string into words.
		//cout<<ss<<endl;
		string temp; // To store individual words
		int count = 0;
		ll x[3];
		while(ss>>temp)
		{
			x[count] = stoi(temp);
			count++;
		}
		if(count==2)
		{
			// Range Minimum Query
			ll a = x[0];
			ll b = x[1];
			ll ans;
			if(a>b)
			{
				ll ans1 = ob.rangeMinimum(0,a,n-1);
				ll ans2 = ob.rangeMinimum(0,0,b);
				ans = min(ans1, ans2);
			}
			/*else if(a==b)
                ans = ob.rangeMinimum(0,0,n-1);*/
			else
				ans = ob.rangeMinimum(0,a,b);

			cout<<ans<<endl;



		}
		else
		{
			// Update Query
			ll a = x[0];
			ll b = x[1];
			ll val = x[2];
			if(a>b)
			{
				ob.rangeUpdate(0,a,n-1,val);
				ob.rangeUpdate(0,0,b,val);
			}
			/*else if(a==b)
                ob.rangeUpdate(0,0,n-1,val);*/
			else
				ob.rangeUpdate(0,a,b,val);
		}

	}

}
