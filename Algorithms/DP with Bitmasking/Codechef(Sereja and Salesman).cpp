# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
# include <unordered_map>
# define ll long long
# define MOD 1000000007

using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

vector<vector<ll> >dp(1<<14, vector<ll>(14+1,-1));
unordered_map<pair<int, int>, int, hash_pair>bad_edges;
unordered_map<int,int>bad_vertices;
unordered_map<int,int>bad_vertices_reverse;
int n_bad_vertices;

ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        ll q = a / m;
        ll t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
       x += m0;

    return x;
}

ll factorial(ll n)
{
    ll res=1;
    while(n)
    {
        res = (res*(n))%MOD;
        n-=1;
    }
    return res;
}

// Initially none of the bad vertices are placed in ordering.
ll valid_orderings(int mask, int idx)
{
	// all the bits are set--> a valid ordering
	if(mask==(1<<n_bad_vertices)-1)
		return 1;

	// If all bad vertices have been explored and no ordering has been found.
	/*if(idx>bad_vertices.size())
		return 0;*/

	if(dp[mask][idx]==-1)
	{
		ll result = 0;
		int last_placed = bad_vertices_reverse[idx];
		// Check bad vertices which have not been put in the ordering.
		for(int i=0;i<n_bad_vertices;i++)
		{
			// If the bad_vertex i already placed in the ordering.
			if(mask & (1<<i))
				continue;


			// If the bad_vertex is not placed in the ordering
			// Check if there exists an edge between this vertex and last placed.
			// If no edge exist, this vertex can be placed in the ordering
			// bad_vertex_idx = i+1 in the map.
			bool condition1 = bad_edges.find({bad_vertices_reverse[i+1], last_placed}) == bad_edges.end();
			bool condition2 = bad_edges.find({last_placed, bad_vertices_reverse[i+1]}) == bad_edges.end();
			bool condition3 = last_placed==-1;
			if(condition1 && condition2 || condition3)
				result = (result + valid_orderings(mask | (1<<i), i+1))%MOD;
		}
		dp[mask][idx] = result;
	}
	return dp[mask][idx];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		bad_vertices.clear();
		bad_vertices_reverse.clear();
		bad_edges.clear();
		for(int i=0;i<dp.size();i++)
			fill(dp[i].begin(),dp[i].end(),-1);

		int N,M;
		cin>>N>>M;
		for(int i=0;i<M;i++)
		{
			int x,y;
			cin>>x>>y;
			bad_edges[{x,y}] = 1;
			bad_edges[{y,x}] = 1;
			bad_vertices[x] = 1;
			bad_vertices[y] = 1;
		}

        int i=1;
		// Giving each bad vertex an index. Start from 1 for easier implementation.
		for(auto itr=bad_vertices.begin();itr!=bad_vertices.end();itr++)
		{
			bad_vertices[itr->first] = i;//itr - bad_vertices.begin()+1;
			bad_vertices_reverse[i] = itr->first;
			i++;
		}
		n_bad_vertices = bad_vertices.size();
		ll ans = (factorial(N) * modInverse(factorial(bad_vertices.size()), MOD))%MOD;
		bad_vertices_reverse[0] = -1;
		bad_vertices[-1] = 0;
		ll x = valid_orderings(0,0);
		ans = (ans*x)%MOD;
		cout<<ans<<endl;


	}

}
