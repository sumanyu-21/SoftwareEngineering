# include <iostream>
# include <stdio.h>
using namespace std;
int main()
{
	float num = 365;
	float denom = 365;
	float p = 1;
	int n = 0;
	while(p>0.1)
	{
		p = p*(num)/denom;
		num--;
		n++;
		cout<<"Probability is "<<p<<" and "<<" no. of people in room are: "<<n<<endl;
	}
}
