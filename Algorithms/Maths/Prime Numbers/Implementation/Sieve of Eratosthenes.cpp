# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

int N = 1000000;
vector<int>p(N,0); // No number is prime

void primeSieve(int n)
{
	p[0] = p[1] = 0;
	p[2] = 1;

	// Let us mark all the potential candidates of prime numbers as 1.
	for(int i=3;i<=n;i+=2)
		p[i] = 1;

	// Sieve update to mark non prime odd numbers as 0.
	for(int i=3;i<=sqrt(n);i++)
	{
		if(p[i])
		{
			// We are incrementing j by 2i because j=i*i will be odd and if we increment by i(odd), we will get even numbers which we have already marked as non prime.
			// Hence we are incrementing by 2i.
			for(int j=i*i;j<=n;j+=2*i)
				p[j] = 0;
		}

	}
}

int main()
{
	primeSieve(100);
	for(int i=0;i<N;i++)
		if(p[i])
			cout<<i<<endl;
}
