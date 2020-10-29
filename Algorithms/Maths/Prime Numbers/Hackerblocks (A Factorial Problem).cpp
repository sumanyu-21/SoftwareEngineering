# include <iostream>
# include <bits/stdc++.h>
# define ll long long
using namespace std;

vector<ll>primes;
vector<ll>mark(1e4+1,0);
unordered_map<ll,ll>p_factors;

void sieve(ll n)
{
	mark[2] = 1;

	// Mark all potential candidate as 1.
	for(ll i=3;i<=n;i+=2)
		mark[i] = 1;

	for(ll i=3;i<=sqrt(n);i++)
	{
		if(mark[i])
		{
			// Unmark invalid primes.
			for(ll j=i*i;j<=n;j+=2*i)
				mark[j] = 0;
		}
	}

	for(ll i=2;i<=n;i++)
	{
		if(mark[i])
        {
            //cout<<i<<endl;
            primes.push_back(i);
        }
	}
}

void primeFactorization(ll k)
{
	// Calculate prime factorization of k
	ll i=0;
	while(primes[i]<=sqrt(k))
	{
	    //cout<<primes[i]<<endl;
		if(k%primes[i]==0)
		{
			while(k%primes[i]==0)
			{
				p_factors[primes[i]]+=1;
				k/=primes[i];
			}
		}
		i++;
	}

	// If k was itself prime.
	if(k!=1)
		p_factors[k]=1;

}

ll powerofprimep(ll n)
{
	ll ans = INT_MAX;
	for(auto itr = p_factors.begin();itr!=p_factors.end();itr++)
	{
		ll p = itr->first;
		ll power = 0; // power of prime p in n!
		while((n/p)!=0)
		{
			power+=n/p;
			p = p*(itr->first);
		}
		ans = min(ans, power/(itr->second));
	}
	if(ans==INT_MAX)
        ans = 0;
	return ans;
}

int main()
{
	int t;
	cin>>t;
	sieve(1e4);
	while(t--)
	{
		//mark.fill(mark.begin(),mark.end(),0);
		//primes.clear();
		p_factors.clear();
		ll n, k;
		cin>>n>>k;
		primeFactorization(k);
		ll ans = powerofprimep(n);
        cout<<ans<<endl;
	}
}
