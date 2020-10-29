# include <iostream>
# include <bits/stdc++.h>
using namespace std;

double expectation(int n)
{
	double ans = 0;
	for(int i=1;i<=n;i++)
		ans+=n/(1.0*i);
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		double ans = expectation(n);
		cout<<fixed<<setprecision(6)<<ans<<endl;
	}
}