# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

# define ll unsigned long long
# define MOD 109546051211

ll compute_overflow(ll n)
{
	ll ans = 1;
	ll fact = 1;
	for(ll i = 1;i<=n;i++)
	{
		fact = (fact*i)%MOD;
		ans = (ans*fact)%MOD;
		cout<<ans<<endl;

	}
	return ans;
}

ll compute(ll n)
{
	for(int ll i=1;i<=n;i++)
	{
		ans = ans*fast_exponen
	}
}

int main()
{
	ll n;
	cin>>n;
	cout<<compute(n);
}
