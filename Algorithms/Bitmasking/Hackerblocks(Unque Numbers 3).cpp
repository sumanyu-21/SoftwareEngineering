# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;
vector<int>bitsum(64,0);

int main()
{
	int n;
	cin>>n;
	vector<int>arr(n);
	int max_=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		max_=max(max_,arr[i]);
	}
	int unique_=0;
	for(int pos=0;pos<log2(max_)+1;pos++)
	{
		// Sum of position pos bits for all the numbers.
		//cout<<pos<<endl;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]&(1<<pos)) // Bit is set
				sum+=1;
		}
		//cout<<sum<<endl;
		int is_set = sum%3;
		unique_+=(1<<pos)*is_set;
	}
	cout<<unique_<<endl;
}
