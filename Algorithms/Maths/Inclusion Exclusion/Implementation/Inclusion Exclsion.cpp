# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

int setBit(int mask)
{
	int ans = 0;
	while(mask)
	{
		mask = mask&(mask-1);
		ans++;

	}
	return ans;
}

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];

	int ans = 0;
	for(int i =1;i<(1<<n);i++)
	{
		int mask = i;
		int product = 1;
		int curr_bit = 0;
		int turned_on = setBit(mask);
		while(mask)
		{
			if(mask&1)
				product*=a[curr_bit];
			mask>>=1;
			curr_bit++;
		}
		if(turned_on&1)
			ans+=k/product;
		else
			ans-=k/product;
	}

	cout<<ans<<endl;


}
