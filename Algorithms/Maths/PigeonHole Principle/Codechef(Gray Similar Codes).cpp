# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
# define ll unsigned long long
using namespace std;

vector<ll>arr;
ll n;

/*bool bruteForce()
{
	// Consider each pair of consecutive numbers.
	bool ans = false;
	for(int p=0;p<n-1;p++)
	{
		ll a = arr[p];
		ll b = arr[p+1];

		// Find which bit is differing.
		ll c = a^b;
		ll pos=0;
		while(c)
		{
			// If bit is set, then this is the position we care about.
			if(pos&1)
				break;
			c>>=1;
			pos++;
		}

		// pos now contains the position for which we need to search other pairs.

		for(int j=0;j<n-1;j++)
		{
			ll x = arr[j];
			ll y = arr[j+1];

			if(x!=a && y!=b)
			{
				ll z = x^y;
				if((z^(1<<pos))==0)
					ans = ans || true;
			}
		}
	}
	return ans;

}*/

/*string bruteForce()
{

	// Check for every position of bit.
	for(int pos=0;pos<65;pos++)
	{
		// Find pairs which have bits different in this position.
		set<ll>my_set;
		for(int p=0;p<n-1;p++)
		{
			ll a = arr[p];
			ll b = arr[p+1];

			if(((a^b)^(1<<pos))==0)
			{
				my_set.insert(a);
				my_set.insert(b);
			}

		}
		if(my_set.size()>=4)
			return "Yes";

	}
	return "No";
}*/

string bruteForce()
{
	ll result;
	ll flag=0;
	for(ll i=1;i<=n-3;i++)
	{
		for(ll j=i+1;j<=n-2;j++)
		{
			/*if(j==i)
				continue;*/
			for(ll k=j+1;k<=n-1;k++)
			{
				/*if(k==i || k==j)
					continue;*/
				for(ll l=k+1;l<=n;l++)
				{
					/*if(l==i || l==j || l==k)
						continue;*/
                    //cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<" "<<arr[l]<<endl;
					result=(((arr[i]^arr[j])^arr[k])^arr[l]);
					//cout<<result<<endl;
					if(result==0)
					{
						flag=1;

						goto theEnd;
					}
				}
			}
		}
	}
	theEnd:
	if(flag==1)
		return "Yes";
	else
		return "No";
}

int main()
{

	cin>>n;
	arr.resize(n+1);
	for(int i=1;i<n+1;i++)
		cin>>arr[i];

	if(n>=130)
		cout<<"Yes";
	else
	{
		/*bool ans = bruteForce();
		if(ans==true)
			cout<<"Yes";
		else
			cout<<"No";*/
        cout<<bruteForce();
	}
}
