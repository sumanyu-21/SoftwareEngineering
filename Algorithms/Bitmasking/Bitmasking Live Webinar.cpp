# include <iostream>
# include <stdio.h>
# include<vector>
# include <string>

using namespace std;

int countSetBits(int n)
{
	int set_bits = 0;
	while(n>0)
	{
		set_bits+= n&1;
		n>>=1;
	}
	return set_bits;
}

int countSetBitsFast(int n)
{
	int count =0;
	while(n)
	{
		count++;
		n = n&(n-1);
	}
	return count;
}

int getIthBit(int n, int i){
	return (n&(1<<i))!=0?1:0;
}

void setIthBit(int &n, int i)
{
	n = n|(1<<i);
}

void clearIthBit(int &n, int i)
{
	n = n&(~(1<<i));
}

vector<string> generteSubsequences(string s)
{
	int n = s.length();
	int total = 1<<(n);
	vector<string>vec(total+1);//+1 for empty string.
	for(int i=0;i<total;i++)
	{
		int mask = i;
		string t = "";
		int j=0;
		while(mask>0)
		{
			if(mask&1)
				t.push_back(s[j]);
			mask>>=1;
			j+=1;
		}
		vec[i] = t;
	}
	return vec;
}
int main()
{
	//int n;
	//cin>>n;
	//cout<<countSetBits(n)<<endl;
	//cout<<countSetBitsFast(n);
	vector<string>vec = generteSubsequences("abc");
	for(auto x:vec)
        cout<<x<<endl;
}
