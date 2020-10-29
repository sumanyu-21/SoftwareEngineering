# include <iostream>
# include <stdio.h>
using namespace std;

long long a, b;
vector<int>primes(sqrt(b)+1,0);
vector<int>segment(b-a+1,1);

void sieve(int n)
{
	p[2] = 1;
	// Mark all potential candidates of primes as 1;
	for(int i=3;i<=sqrt(n);i++)
	{
		// Mark all non primes as 0;
		for(int j=i*i;j<=n;j+=2)
			primes[i] = 0;
	}
}

void segmentedSieve(long long a, long long b)
{
	sieve();
	for (long long i=2;i<=sqrt(b);i++)
	{  
		if(primes[i])
		{
			if(p[i]==segment[j])
				continue; 
			for(int j=0;j<(b-a+1);j++)
			{
				if(segment[j]%i==0)
					segment[j] = 0;
			}
		}
	}
}

int main()
{


}