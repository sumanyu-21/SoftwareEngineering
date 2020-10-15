#include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

int set_bits(int n)
{
	int count = 0;
	while(n)
	{
		n&=(n-1);
		count++;
	}
	return count;
}
int main() 
{

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<set_bits(n)<<endl;
	}
}