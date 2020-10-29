# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

int N = 1000000;
vector<int>p(N+1,0);
vector<int>primes;
unordered_map<int,int>prime_factors;

void sieve(int n)
{
    //cout<<n<<endl;
	p[2] = 1;
	for(int i=3;i<=n;i+=2)
		p[i] = 1;

	for(int i=3;i<=sqrt(n);i+=2)
	{
		if(p[i])
		{
		    //cout<<i<<endl;
			for(int j=i*i;j<=n;j+=2*i)
				p[j] = 0;
		}
	}
	for(int i=2;i<=n;i++)
    {
        if(p[i])
        {
            //cout<<p[i]<<endl;
            primes.push_back(i);
        }
    }
}

void primeFactorization(int n)
{
	int i=0;
	while(primes[i]<=sqrt(n))
	{
	    //cout<<primes[i]<<" "<<sqrt(n)<<endl;
		if(n%primes[i]==0)
		{
		    //cout<<n<<endl;
			//prime_factors[primes[i]]+= 1;
			while(n%primes[i]==0)
			{
				n/=primes[i];
				prime_factors[primes[i]]+=1;
			}
		}
		i++;
	}

	// One corner case: If n is prime
	if(n!=1)
		prime_factors[n]=1;

}


int main()
{
	int x;
	cin>>x;
	sieve(x);
	primeFactorization(x);
	for(auto itr=prime_factors.begin();itr!=prime_factors.end();itr++)
		cout<<itr->first<<"  "<<itr->second<<endl;
}
