# include <iostream>
# include <bits/stdc++.h>
# define ll unsigned long long
using namespace std;
vector<int>mark(sqrt(500)+1);
vector<int>primes;
unordered_map<int,int>p_factors;

void sieve(int n)
{
	mark[2] = 1;
    //cout<<n;
	for(int i=3;i<=n;i+=2)
		mark[i] = 1;

	for(int i=3;i<=sqrt(n);i++)
	{
		if(mark[i])
		{
			for(int j=i*i;j<=n;j+=2*i)
				mark[j] = 0;
		}
	}

	for(int i=2;i<=n;i++)
	{
	    //cout<<i;
		if(mark[i])
			primes.push_back(i);
	}
}

ll primeFactorization(int n)
{
	ll ans = 0;
	// Compute prime factorization of n! using DP.
	for(int i=2;i<=n;i++)
	{
		int k = i;
		int j=0;
		while(j<primes.size() && primes[j]<=sqrt(k))
		{
			if(k%primes[j]==0)
			{
				while(k%primes[j]==0)
				{
					p_factors[primes[j]]+=1;
					k/=primes[j];
				}
			}
			j++;
		}

		if(k!=1)
			p_factors[k]+=1;

		ans+= (1ULL<<(p_factors.size()-1));
	}

	/*int distinct_primes = p_factors.size();
	return (1<<(distinct_primes-1));*/
	return ans;
}

int main()
{
	int n;
	cin>>n;
	sieve(sqrt(n));
	cout<<primeFactorization(n);
}
