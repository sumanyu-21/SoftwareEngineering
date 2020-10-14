# include <iostream>
# include <stdio.h>
# include <map>
# include <algorithm>
# include<vector>
# include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

vector<int>arr;

int main()
{
	int n;
	cin>>n;
	arr.resize(n+5);

	unordered_map<ll, int>left;
	unordered_map<ll, int>right;

	ll total_sum = 0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		total_sum+=arr[i];
        right[arr[i]]+=1;
	}
	//string ans="NO";
	if(total_sum%2==0)
	{
		ll partition_sum = total_sum/2;
		ll running_sum = 0;

		for(int i=0;i<n;i++)
		{
		    left[arr[i]]+=1;
            running_sum+=arr[i];
            right[arr[i]]-=1;

			if(running_sum==partition_sum)
			{
				cout<<"YES"<<endl;
				return 0;
			}
			else if(running_sum<partition_sum)
			{
				ll value = partition_sum-running_sum;
				if(right.find(value)!=right.end() && right[value]>0)
				{
					cout<<"YES"<<endl;
					return 0;
				}
			}

			else
			{
				long long value = running_sum-partition_sum;
				if(left.find(value)!=left.end())
				{
					cout<<"YES"<<endl;
					return 0;
				}
			}

		}


	}
	cout<<"NO"<<endl;
	return 0;
}
