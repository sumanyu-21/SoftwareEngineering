# include <iostream>
# include <bits/stdc++.h>
using namespace std;


int n = 4;
int dist[10][10] = {
	{0,20,42,25},
	{20,0,30,34},
	{42,30,0,10},
	{25,34,10,0}
};

int edge[10][10] = {
	{0,1,1,1},
	{1,0,1,1},
	{1,1,0,1},
	{1,1,1,0}
};

vector<vector<int> >dp((1<<n),vector<int>(n,-1));
int src = 0;

int topDown(int mask, int current_node)
{
	if(mask==(1<<n)-1)
	{
		if(edge[current_node][src])
			return dist[current_node][src];
		else
			return INT_MAX;
	}

	if(dp[mask][current_node]==-1)
	{
		// Check each univisited node in current mask
		int ans = INT_MAX;
		for(int i=0;i<n;i++)
		{
			if(mask&(1<<i))
				continue;

			// If the the node is not visited and an edge is present between current_node and node we are looking.
			if(edge[current_node][i])
				ans = min(ans, topDown(mask | (1<<i), i) + dist[current_node][i]);
		}
		dp[mask][current_node] = ans;
	}
	return dp[mask][current_node];
}

int bottomUp()
{
    int ans = INT_MAX;
    dp[1][0] = 0;
    //for(int i=0;i<n;i++)
        //dp[(1<<i)][i] = 0;

    for(int mask=1;mask<(1<<n);mask++)
    {
        for(int current_node=0;current_node<n;current_node++)
        {
            if(dp[mask][current_node]<INT_MAX)
            {
                // Check for nodes whch are yet not visited.
                for(int j=0;j<n;j++)
                {
                    // If the node is yet not visited and an edge exists between current node and node j.
                    if(((mask & (1<<j))==0) && edge[current_node][j])
                    {
                        int updated_mask = mask|(1<<j);
                        dp[updated_mask][j] = min(dp[updated_mask][j], dp[mask][current_node] + dist[current_node][j]);
                    }
                }
            }
            // If all nodes are visited and an edge exists between current node back to src node.
            if(mask==(1<<n)-1 && edge[current_node][src])
            {   //cout<<dp[mask][current_node] + dist[current_node][src]<<endl;
                ans = min(ans, dp[mask][current_node]+dist[current_node][src]);
                //cout<<ans<<endl;
            }
        }
    }
    return ans;

}

int main()
{
	cout<<topDown(1,0)<<endl;
	/*for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    for(int i=0;i<(1<<n);i++)
        fill(dp[i].begin(),dp[i].end(),INT_MAX);
    cout<<bottomUp()<<endl;
    /*for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<4;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
}

