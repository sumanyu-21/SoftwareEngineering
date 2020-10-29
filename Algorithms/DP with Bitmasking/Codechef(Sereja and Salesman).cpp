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

int dp[(1<<14)][15][15];
unordered_map<pair<int, int>, int, hash_pair>bad_edges;
unordered_map<int,int>bad_vertices;
unordered_map<int,int>bad_vertices_reverse;
int n_bad_vertices;

long long poww(long long a, long long b){
    long long ans = 1;
    while (b){
        if (b % 2) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return ans;
}

long long fa[111111];
long long rev[111111];

long long cnk(int n, int k){
    return (fa[n] * rev[k] % MOD * rev[n - k]) % MOD;
}


int main()
{
	int t;
	cin>>t;
	fa[0] = rev[0] = 1;
    for (int i = 1; i <= 100000; i++){
        fa[i] = (fa[i - 1] * i) % MOD;
        rev[i] = poww(fa[i], MOD - 2);
    }
	while(t--)
	{
		bad_vertices.clear();
		bad_vertices_reverse.clear();
		bad_edges.clear();
		memset(dp,0, sizeof(dp));

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

        int k=0;
		// Giving each bad vertex an index. Start from 1 for easier implementation.
		for(auto itr=bad_vertices.begin();itr!=bad_vertices.end();itr++)
		{
			bad_vertices[itr->first] = k;//itr - bad_vertices.begin()+1;
			bad_vertices_reverse[k] = itr->first;
			k++;
		}
		//for(auto itr = bad_vertices_reverse.begin();itr!=bad_vertices_reverse.end();itr++)
            //cout<<itr->first<<" "<<itr->second<<endl;

		n_bad_vertices = bad_vertices.size();
		//cout<<n_bad_vertices<<endl;

		ll ans = 0;
		for (int i=0;i<n_bad_vertices;i++)
			dp[1<<i][i][0] = 1;

		for (int mask = 1;mask < (1<<n_bad_vertices); mask++)
		{
			for (int last_placed = 0; last_placed<bad_vertices.size(); last_placed++)
			{
				for(int taken = 0; taken < bad_vertices.size(); taken++)
				{
					if(dp[mask][last_placed][taken]>0)
					{
					    //cout<<mask<<" "<<last_placed<<" "<<taken<<" "<<dp[mask][last_placed][taken]<<endl;
						// Check if jth bad vertex has been placed in order.
						for(int j=0;j<bad_vertices.size();j++)
						{
							// If placed, do nothing
							if(mask & (1<<j))
								continue;

							// If not placed, check if there exists an edge between this vertex and last placed vertex.
							bool condition1 = bad_edges.find({bad_vertices_reverse[last_placed], bad_vertices_reverse[j]})==bad_edges.end();
							//bool condition2 = bad_edges.find({bad_vertices_reverse[j], bad_vertices_reverse[last_placed]})==bad_edges.end();
							//cout<<mask<<" "<<last_placed<<" "<<taken<<" "<<dp[mask][last_placed][taken]<<endl;
							//cout<<condition1<<endl;
							int updated_mask = (mask | (1<<j));
							if(condition1)
								dp[updated_mask][j][taken] = (dp[updated_mask][j][taken] + dp[mask][last_placed][taken])%MOD;

							else
								dp[updated_mask][j][taken+1] = (dp[updated_mask][j][taken+1] + dp[mask][last_placed][taken])%MOD;

                            //dp[mask ^ (1<<j)][j][taken + bad_edges[make_pair(bad_vertices_reverse[last_placed], bad_vertices[j])]] = (dp[mask][last_placed][taken] + dp[mask ^ (1<<j)][j][taken + bad_edges[make_pair(bad_vertices_reverse[last_placed], bad_vertices[j])]])%MOD;
						}

						// We can calculate number of combinations here only.
						// If all the bad_vertices are placed, then for current number of taken vertices, this is the final answer. In other words
						// this state of DP will not be updated anymore.
						if(mask==(1<<n_bad_vertices)-1)
						{

							ll val = dp[mask][last_placed][taken];
							if(N-taken<n_bad_vertices)
								continue;
                            //cout<<mask<<" "<<last_placed<<" "<<taken<<" "<<val<<endl;
							val = (val * cnk(N-taken, n_bad_vertices))%MOD;
							//cout<<val<<endl;
							val = (val * fa[N-n_bad_vertices])%MOD;
							//cout<<val<<endl;
							ans = (ans+val)%MOD;
							//cout<<ans<<endl;
						}

					}
				}
			}
		}
        if(n_bad_vertices==0)
            ans = fa[N];
        cout<<ans<<endl;

	}

}
