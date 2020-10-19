# include <iostream>
# include <stdio.h>
using namespace std;

int countSetBits(int n)
{
	int ans = 0;
	while(n)
	{
		// Remove last set bit.
		n = n&(n-1)
		ans++;
	}
	return ans;
}

int main()
{
	int N = spellChart.size()
	vector<int>adjMat(N,0);

	// Creating mask for each adjacency list
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(spellChart[i][j]=='Y')
				adjMat[i] = adjMat[i] | (1<<j);


	// Store set bits for each of the [0:2^n]
	vector<int>bitCount((1<<(2*N)),0);
	for(int i=0;i<(1<<(2*N)); i++)
		bitCount[i] = countSetBits(i);

	vector<int>dp(1<<N,INT_MAX);

	dp[0] = 0; // If no topological ordering, cost is 0;

	for(int mask=0;mask<dp.size();mask++)
	{
		// Consider all masks.
		for(int i=0;i<N;i++)
		{
			// Consider all unset bits for given mask.
			if(mask&(1<<i))
				continue; // If current bit is already set in mask, do nothing.
			
			// Else calculate nxtMask.By setting the ith bit equal to 1
			int nxtMask = mask | (1<<i);
			int res = dp[mask] + bitCount(adjMat[i] & nxtMask);
			dp[nxtMask] = min(dp[nxtMask], res);
		}
	}
	// All ones in our mask.
	return dp[(1<<N)-1];




}