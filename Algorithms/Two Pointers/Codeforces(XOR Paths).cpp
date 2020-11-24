# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
# define ll long long
using namespace std;
ll arr[20][20];
unordered_map<ll,ll> path_xor[20][20];

ll half, other_half;
ll ans, n, m;

void go(ll i, ll j, ll path_length, ll XOR)
{
	if(i>n || j>m)
		return;
	// If path length = (n+m-1)/2, return
	if(path_length == half)
	{
		path_xor[i][j][XOR]+=1;
		return;
	}

	go(i+1,j,path_length+1, XOR^arr[i][j]);
	go(i,j+1, path_length+1, XOR^arr[i][j]);
}

void solve(ll i, ll j, ll path_length, ll k)
{
	if(i<0 || j<0)
		return;
	if(path_length == other_half)
	{
		ll y = k^arr[i][j];
		if(path_xor[i][j].find(y)!=path_xor[i][j].end())
		{
			ans+= path_xor[i][j][y];

		}
		return;
	}

	solve(i-1,j, path_length+1, k^arr[i][j]);
	solve(i,j-1, path_length+1, k^arr[i][j]);

	return;
}

int main()
{
	ll k;
	cin>>n>>m>>k;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
			cin>>arr[i][j];
	}

	half = (n+m-2)/2;
	other_half = n+m-2 - half;
	go(0,0,0,0);
	solve(n-1,m-1,0,k);
	cout<<ans<<endl;



}
