# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>grid(11,vector<int>(11));

void allPaths(int i,int j, vector<vector<int>>&matrix)
{
	// If reached to n-1,m-1--> We have found a path.
	if(i== n-1 && j== m-1)
	{
	    matrix[i][j] = 1;
		for(int row=0;row<n;row++)
		{
			for(int col=0;col<m;col++)
				cout<<matrix[row][col]<<" ";
			cout<<endl;
		}
		matrix[i][j] = 0;
		cout<<endl<<endl;
		return;
	}

	// If exceeded the grid, return;
	if(i<0 || j<0 || i==n || j==m)
		return;

	// If we cannot move to this position return;
	if(grid[i][j] || matrix[i][j])
		return;

	// Mark this postion;
	matrix[i][j] = 1;
	// Move to next position
	allPaths(i+1,j,matrix); // Explore all paths by moving to next row.
	allPaths(i,j+1,matrix); // Explre all paths by moving to next column.
	allPaths(i-1,j,matrix);
	allPaths(i,j-1,matrix);
	matrix[i][j] = 0; // All paths with this cell marked has been explored.
	return;

}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    }
    vector<vector<int>>matrix(n,vector<int>(m,0));
    allPaths(0,0,matrix);
}
