# include <iostream>
# include <stdio.h>
# include <string>
# include <bits/stdc++.h>

using namespace std;

vector<int>arr;

int convertToInt(string s)
{
	stringstream object(s);
	int x = 0;
	object>>x;
	return x;
}

void approach1(int n)
{
	int total_digits = log10(1e9)+1;

	//Generate all lucky numbers.
	for (int i=1;i<=total_digits;i++)
	{
		// Generate i digit numbers. Total such numbers = 2^i
		for (int j=1;j<=(1<<i);j++)
		{
			// Scan each position of i digit numbers.
			// If bit is set, then consider to be digit 7.
			// If not set, then consider to be digit 4.
			string s1 = "";
			//string s2 = "";
			int index = 1;
			int current_number = j;
			while(index<=i)
			{
				if(current_number&1) // If bit is set, then consider it to be 7
                    s1.push_back('7');
				else
                {
                    s1.push_back('4');
                }
				index++;
				current_number>>=1;
			}
			arr.push_back(convertToInt(s1));
		}
	}
	sort(arr.begin(), arr.end());
	auto itr = lower_bound(arr.begin(),arr.end(), n);
	cout<<itr-arr.begin()+1<<endl;
}

int approach2(int n)
{
	// if d is the number of digits in n. then 1 digit, 2 digit, .... (d-1) digit numbers are smaller than n;
	// Such numbers are 2^1+2^2+..2^(d-1)
	// We can use following 2^0 + 2^1...2^(d-1) = 2^d - 1;
	int digits = log10(n)+1;
	int ans = 0;
	if(digits>1)
        ans = (1<<digits) - 2;
	// Now count d digit numbers smaller than given number;
	int length = 0;
	while(n)
	{
		if(n%10==7)
		{
			ans+=(1<<length);
		}
		n/=10;
		length++;
	}
	//ans gives us numbers smaller than n;
	cout<<ans+1<<endl;
}

int main()
{
	int n;
	cin>>n;
	//approach1(n);
	approach2(n);

}
