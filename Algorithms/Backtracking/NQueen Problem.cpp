# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

int n;
int cnt;


bool canPlace(int i, int j, vector<vector<int>>&m)
{
	// Check if we can place in the column;
	for(int col = 0;col<n;col++)
		if(m[i][col])
			return false;

	// Check if we can place in the row;
	for(int row=0;row<n;row++)
		if(m[row][j])
			return false;

	// Check if we can place in that diagnal. e have to check in the upper part of the diagnol only
		// as the bottom is yet not filled.
	int ii=i, jj=j;
	while(ii>=0 && jj<n)
	{
		if(m[ii--][jj++])
			return false;
	}
	ii = i,jj=j;
	while(ii>=0 && jj>=0)
    {
        if(m[ii--][jj--])
            return false;

    }
	return true;




}

void allPaths(int i, vector<vector<int>>&m)
{
	// Reached to the end of row--> Valid Configuration found
	if(i==n)
	{
		// Print the matrix;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<m[i][j]<<" ";
            cout<<endl;
		}
		cnt++;
		cout<<endl<<endl;
		return;
	}

	// Tryt to place in the current row.
	for(int j=0;j<n;j++)
	{
		// If we can place in the current cell.
		if(canPlace(i,j, m))
		{
			// Place the queen and move to next row.
			m[i][j] = 1;
			allPaths(i+1,m);
			// Unset this position when returning;
			m[i][j] = 0;
		}

	}
}

int main()
{
	cin>>n;
	vector<vector<int>>m(n,vector<int>(n,0));
	allPaths(0,m);
	cout<<"Number of possible configurations are "<<cnt<<endl;
}
