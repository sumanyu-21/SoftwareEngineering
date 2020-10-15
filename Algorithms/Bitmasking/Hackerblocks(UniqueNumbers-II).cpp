# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int aXORb = 0;
	for(auto x:arr)
		aXORb^=x;

	// check for any set bit--> I will check for first set bit.
	int set_bit = aXORb & (-aXORb);
	//cout<<aXORb<<" "<<set_bit<<endl;

	// Seperate the given array in 2 parts
	// Part a containing all numbers with this bit set(a will lie in this part).
	// Part b containing all numbers with this bit not set(b will lie in this part).

	int a=0;
	int b=0;

	// Finding a;
	for(auto x:arr)
	{
		if((set_bit & x)>0)
            a^=x;
		else
            b^=x;
	}
	if(a>b)
		swap(a,b);
	cout<<a<<" "<<b<<endl;


}
