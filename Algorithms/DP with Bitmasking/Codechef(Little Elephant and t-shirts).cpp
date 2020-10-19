# include <iostream>
# include <stdio.h>
# include <string>
# include <bits/stdc++.h>
using namespace std;
# define ll long long
# define mod 1000000007

int N;
vector<vector<int> > arr(10);
vector<vector<ll> >dp((1<<10),vector<ll>(101,-1));

int stoi(string &s)
{
	stringstream ob(s);
	int res;
	ob >> res;
	return res;
}

ll go(int mask, int t_id)
{

    // If all the persons are given t_shirt then return 0;
	if(mask==(1<<(N))-1)
		return 1;

	// If tshirt_id increases by more than 100, return 0. Not possible.
	if(t_id>100)
        return 0;

	if(dp[mask][t_id]==-1)
	{
		ll result = 0;
		// Consider all persons who have not been given t-shirt and try to give
		// t-shirt = t_id to the person.
		for (int i=0;i<N;i++)
		{
			// In case the person is wearing t-shirt then do nothing.
			if(mask & (1<<i))
				continue;

			// Else check if the person has tshirt of id t_id;
			for(int j=0;j<arr[i].size();j++)
			{
				// Give the t_id tshirt to person i;
				if(arr[i][j] == t_id)
                {
                    result = (result + go(mask|(1<<i), t_id+1))%mod;
                    break;
                }

			}

		}
		// Don't give this t_shirt to any person;
		result = (result + go(mask, t_id+1))%mod;
		dp[mask][t_id] = result;
	}
	return dp[mask][t_id];

}

int main()
{
	//arr.reserve(10);
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<dp.size();i++)
			fill(dp[i].begin(),dp[i].end(),-1);
		for(int i=0;i<10;i++)
			arr[i].clear();
		cin>>N;
		string s;
		cin.get();
		for(int i=0;i<N;i++)
		{
		    // Getline takes input in string object. If we use this, we would have to break string into token using string tokenizer function.
		    // String stream takes input in buffer of characters. String stream is easier to use.
			getline(cin, s);
			stringstream ss(s);
			string temp;
			while(ss>>temp)
                arr[i].push_back(stoi(temp));
		}
		ll res=go(0,1);
		if(res==-1)
			res=0;
		cout<<res<<endl;
	}
}
