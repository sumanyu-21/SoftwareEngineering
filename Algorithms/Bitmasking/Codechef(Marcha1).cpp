# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

vector<int>arr(25,0);

int subSetSum(int mask,int m)
{
	int i=0;
	while(mask)
	{
		if(mask&1)
        {
            m-=arr[i];
            if(m<0)
                return 0;
        }
        mask>>=1;
		i+=1;
	}
	//cout<<m<<endl;
	if(m==0)
		return 1;
	return 0;
}

int checkSubSetSum(int m, int n)
{

	// Check for all possible subsets by creating a mask;
	int range = (1<<n);
	for(int i=1;i<range;i++)
	{

	    int mask=i;
	    //cout<<mask<<" ";
		if(subSetSum(mask, m))
			return 1;
	}
	return 0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		//vector<int>arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int ans = checkSubSetSum(m,n);
		if(ans==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
	}
	return 0;
}
