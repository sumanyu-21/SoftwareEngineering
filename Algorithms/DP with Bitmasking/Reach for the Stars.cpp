# include <iostream>
# include <stdio.h>
using namespace std;
int main()
{
	int R,C;
	cin>>R>>C;
	
	vector<bool,vector<bool>>isMarked(R,vector<bool>(C,0));
	vector<bool,vector<bool>>canMark(R,vector<bool>(C,0)); // This will come in handy for situations when we are at the
														   // edge of the grid and cannot place the stamp there.

	for(int i=0;i<R;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<C;j++)
			isMarked[i][j] = s[j]=='#';
	}
	for(int i=1;i<R-1;i++)
	{
		for(int j=1;j<C-1;j++)
			canMark[i-1][j] = isMarked[i-1][j] && isMarked[i+1][j] && isMarked[i][j] && isMarked[i][j-1] && isMarked[i][j+1];
			// Here we have used i-1 because we are using the topmst cell of stamp as our refrence.
	}

	int stampMask = (1<<0) | (1<<C) | (1<<(C-1)) | (1<<(C+1)) | (1<<(2C));

	// This is not space saving DP.
	// The number of maskes should be [1<<(2*C+1)]??
	vector<int,vector<int>>dp(R*C+1, vector<int>(1<<(2*C+1),INT_MAX));

	// We are at position 0 and nothing infront of us is marked.
	dp[0][0] = 0;


	// For keeping track of cell in row major order.
	int currCell = -1;

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			currCell++;
			int nxtCell = currCell+1;

			//Loop Over all masks
			for(int mask=0; mask<(1<<(2*C+1)); mask++) if(dp[currCell][mask]<INT_MAX) // Will help prevent integer overflow.
			{

				// Either Mark the cell. Only possible in case we can mark the given cell.
				if(canMark[i][j])
				{
					int nxtMask = (mask | stamp)>>1; // mask in case we place the stamp.
													 // But we need to move to next step and hence we will right shift by one.
					dp[nxtCell][nxtMask] = min(dp[nxtCell][nxtMask], dp[currCell][mask]+1);
				}

				// Or choose not to mark the cell. But we can choose not to mark the cell only when,
				// (i) Either the cell does not need to be marked--> isMarked[i][j]=0
				// (ii) Or, the cell has already been marked--> mask&1 >0;
				else
				{
					if(!isMarked[i][j] || (mask & 1) >0) // We can't leave this cell empty.
					{
						int nxtMask = (mask>>1);
						dp[nxtCell][nxtMask] = min(dp[nxtCell][nxtMask], dp[currCell][mask]);
					}
				}
			}
			
		}
	}
	string res = "impossible";
	// If nothing is infront of me when I cross the grid, we have found some minimum number
	// of stamps to cover the grid in required manner.
	if(dp[R*C][0] <INT_MAX)
		res = to_string(dp[R*C][0]);

	cout<<res<<endl;

	
}