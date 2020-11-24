# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;
vector<int>stalls(1e5+1);

bool comp(int x, int y)
{
	return x<y;
}

bool possible(int min_dist, int n, int c)
{
	int i=1;
	c--;
	int last_placed = stalls[0];
	while(i<n && c>0)
	{
		if(stalls[i]-last_placed>=min_dist)
        {
            //cout<<stalls[i]<<" "<<last_placed<<endl;
            c--;
            last_placed = stalls[i];
        }
		i++;
	}
	if(c==0)
		return true;
	else
		return false;
}

int binarySearch(int start, int end, int n, int c)
{

	int ans = 0;
	while(start<=end)
	{
		// Check if mid is possible as the minimum distance.
		int mid = start + (end-start)/2;
		//cout<<mid<<endl;
		if(possible(mid, n, c)) // It is possible with mid as the minimum distance, then update the minimum distance between any 2 cows.
		{
		    //cout<<start<<" "<<end<<" "<<mid<<" "<<ans<<endl;
			ans = max(ans, mid);
			start=mid+1;
		}
		else
			end=mid-1;

	}
	return ans;
}


int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n,c;
		cin>>n>>c;
		for(int i=0;i<n;i++)
			cin>>stalls[i];
		sort(stalls.begin(),stalls.begin()+n,comp);

		cout<<binarySearch(0, 1e9+1, n, c)<<endl;
	}

}
