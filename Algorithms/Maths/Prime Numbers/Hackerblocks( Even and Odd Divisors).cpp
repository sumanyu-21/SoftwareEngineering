# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
# define ll long long
using namespace std;

vector<int>mark(sqrt(1e5)+1);
vector<int>primes;
unordered_map<int,int>p_factors;

void sieve(int n)
{
	mark[2] = 1;
	for(int i=3;i<=n;i+=2)
		mark[i] = 1;

	for(int i=3;i<=sqrt(n);i+=2)
	{
		if(mark[i])
		{
			for(int j=i*i;j<=n;j+=2*i)
				mark[j] = 1;
		}
	}

	for(int i=2;i<=n;i++)
	{
		if(mark[i])
			primes.push_back(i);
	}
}

ll power(int a, int x)
{
	ll result = 1;
	while(x)
	{
		result*=a;
		x--;
	}
	return result;
}

void primeFactorization(int n)
{
	int i=0;
	while(i<primes.size() && primes[i]<=sqrt(n))
	{
		if(n%primes[i]==0)
		{
			while(n%primes[i]==0)
			{
				p_factors[primes[i]]+=1;
				n/=primes[i];
			}
		}
		i++;
	}

	if(n!=1)
		p_factors[n]+=1;
    //cout<<p_factors.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int q;
	cin>>q;
	sieve(sqrt(1e5));
	while(q--)
	{
		ll a=1, b=1;
		p_factors.clear();
		int n;
		cin>>n;
		primeFactorization(n);
		if(p_factors.find(2)==p_factors.end())
            p_factors[2] = 0;
		for(auto itr=p_factors.begin();itr!=p_factors.end();itr++)
		{
		    //cout<<itr->first<<" "<<itr->second<<endl;
		    //cout<<itr->first<<itr->second<<endl;
			if(itr->first==2)
			{
				b = (1<<(itr->second+1))-3;
				//cout<<b<<endl;
			}
			else
			{
				a = a*(power(itr->first, itr->second+1)-1)/(itr->first-1);
			}
		}
		//cout<<a<<" "<<b<<endl;
		cout<<a*b<<endl;

	}
}
