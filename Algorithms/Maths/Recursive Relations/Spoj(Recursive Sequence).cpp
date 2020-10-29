# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
# define ll long long
# define MOD 1000000000
using namespace std;

vector<vector<ll> >matrixMultiply(vector<vector<ll> >A, vector<vector<ll> >B)
{
	int A_row = A.size();
	int B_col = B[0].size();
	vector<vector<ll> >ans(A_row,vector<ll>(B_col,0));

	for(int i=0;i<A_row;i++)
	{
		for(int j=0;j<B_col;j++)
		{
			for(int k=0;k<B.size();k++)
				ans[i][j] = (ans[i][j] + (A[i][k]%MOD*B[k][j]%MOD)%MOD)%MOD;
		}
	}
	return ans;
}

vector<vector<ll> > matrixExponentiation(vector<vector<ll> >arr, ll n)
{
	int R = arr.size();

	// Creating an identity matrix.
	vector<vector<ll> >ans(R,vector<ll>(R,0));
	for(int i=0;i<R;i++)
		ans[i][i] = 1;

	while(n>0)
	{
	    //cout<<n<<endl;
		//If bit is set.
		if(n&1)
			ans = matrixMultiply(arr, ans);
		arr = matrixMultiply(arr, arr);
		n>>=1;
	}
    return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k;
		cin>>k;


		vector<vector<ll> >F(k,vector<ll>(1,0));
		vector<vector<ll> >T(k,vector<ll>(k,0));

		// Creating F vector of size Kx1;
		for(int i=k-1;i>=0;i--)
			cin>>F[i][0];

		// Creating transformation matrix.
		for(int i=0;i<k;i++)
			cin>>T[0][i];

		for(int i=1;i<k;i++)
			T[i][i-1] = 1;

		ll n;
		cin>>n;
		// Calculating T^(n-k)
		if(n-k<=0)
            cout<<F[n-1][0]<<endl;
        else
		{
		    vector<vector<ll> >ans = matrixExponentiation(T,n-k);
            vector<vector<ll> >res= matrixMultiply(ans, F);
            cout<<res[0][0]<<endl;
		}
	}
}
