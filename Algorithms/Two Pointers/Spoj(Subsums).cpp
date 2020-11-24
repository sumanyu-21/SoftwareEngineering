# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
# define ll long long
using namespace std;

ll dp[(1<<17)][17];

void generate_subsets(ll mask, ll pos, vector<ll> &arr, vector<ll> &subset, ll n)
{
	// We have scanned all elements and have exceeded the limit.
	if(pos==n-1)
	{
	    //cout<<"entered"<<endl;
		subset.push_back(dp[mask][pos] + arr[pos]); // Include the element
		//if(mask!=0)
        subset.push_back(dp[mask][pos])	;		// Do not include the element.
		//cout<<subset.size()<<endl;
		return;
	}


	// Include this element.
	ll updated_mask = mask | (1<<pos);
	dp[updated_mask][pos+1] = dp[mask][pos] + arr[pos];
	generate_subsets(updated_mask, pos+1, arr, subset, n);

	dp[mask][pos+1] = dp[mask][pos];
	generate_subsets(mask, pos+1, arr, subset, n);

	return;

}

bool comp(ll x,ll y)
{
	return x<=y;
}

int main()
{
	ll N,A,B;
	cin>>N>>A>>B;
	ll n1 = N/2;
	ll n2 = N-n1;

	vector<ll>subsetA,subsetB;
	subsetA.reserve((1<<n1)+1);
	subsetB.reserve((1<<n2)+1);

	vector<ll>arr1(n1);
	vector<ll>arr2(n2);
	for(ll i=0;i<n1;i++)
		cin>>arr1[i];
	for(ll i=0;i<n2;i++)
		cin>>arr2[i];

    if(N==1)
    {
        int ans =0;
        if(A<=arr2[0] && arr2[0]<=B)
            ans = 1;
        cout<<ans<<endl;
        return 0;

    }
	generate_subsets(0,0,arr1,subsetA, n1);
	//cout<<sizeof(dp)<<endl;
	memset(dp,sizeof(dp),0);
	//cout<<sizeof(dp)<<endl;
	generate_subsets(0,0,arr2,subsetB, n2);

	// Sorting subset B for performing binary search.
	sort(subsetB.begin(),subsetB.end(),comp);

    /*for(ll i=0;i<subsetA.size();i++)
        cout<<subsetA[i]<<" ";
    cout<<endl;
    for(ll i=0;i<subsetB.size();i++)
        cout<<subsetB[i]<<" ";

    cout<<endl;*/
	ll ans = 0;
	for(ll i=0;i<subsetA.size();i++)
	{

		// For each subset sum, perform binary search to find the required element.
		ll x = B-subsetA[i];
		ll y = A-subsetA[i];
		auto itr1 = upper_bound(subsetB.begin(), subsetB.end(), x);
		auto itr2 = lower_bound(subsetB.begin(), subsetB.end(), y);
		//cout<<*itr1<<" "<<*itr2<<endl;
		//cout<<x<<" "<<y<<" "<<itr1-itr2<<endl;
		ans += itr1-itr2;
		/*if(subsetA[i]==0)
        {
            if((*itr2)<=0 && (*(itr1-1))>=0)
                ans-=1;
        }*/
	}
	/*for(int i=0;i<subsetA.size();i++)
    {
        if(A<=subsetA[i] && subsetA[i]<=B)
            ans++;
    }
    for(int i=0;i<subsetB.size();i++)
    {

        if(A<=subsetB[i] && subsetB[i]<=B)
            ans++;
    }*/
	cout<<ans<<endl;

}
