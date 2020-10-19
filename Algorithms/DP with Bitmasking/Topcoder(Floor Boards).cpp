# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>

using namespace std;

int dp[10][10][2][(1<<9)];
int H,W;

int go(int i, int j, int b, int mask)
{
	if(j==W)
		go(i+1,0,0,mask); // Go to next row.No board is running behind us and the vertical board configuration remains same.

	if(i==H)
		return 0; // We have explored all the cells in our DP.

	if(dp[i][j][b][mask]!=INT_MAX)
	{
		int res = INT_MAX;
		int missingCol = mask & (~(1<<j)) // Turning off the ith bit in mask.
		// If (i,j) is blocked.
		if(blocked[i][j])
		{
			res = min(res,go(i,j+1,0,missingCol));// Update the mask to turn off a vertical board at column j if it was running.
			
		}


		// If (i,j) is not blocked.
		else
		{
			// If horizontal board running, extend it.
			// If nt running, start new horizontal board.
			// If vertical board running, extend it.
			// If not running, start new vertical board.

			if(b==1)// Continue horizontal board.
				res = min(res,go(i,j+1,0,missingCol)); // We will turn off the vertical board running as we have started a horizontal board.

			if(b!=1)// Start new horizontal board
				res = min(res, go(i,j+1,1,missingCol) + 1); // We will 

			if(mask & (1<<j))// Continue vertical board
				res = min(go(i, j+1, 0, mask));

			if(!(mask & (1<<j)))// Start new vertical board
				res = min(res, go(i, j+1, 0, mask | (1<<j)) + 1);

		}

		dp[i][j][b][mask] = res;
	}
	return dp[i][j][b][mask];


}

int main()
{
	
	H = room.length;
	W = room.width;
	vector<bool,vector<bool>>blocked(10,std::vector<bool>(10));

	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
			blocked[i][j] = room[i][j]=='#';

	return go(0,0,0,0);
		
}
