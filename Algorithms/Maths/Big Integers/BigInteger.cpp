# include <iostream>
# include <bits/stdc++.h>
using namespace std;

void multiply(int *a, int &n, int no)
{
	// array 1 2 3 0 0 0 by number 4
	// n is the last position filled.

	int carry = 0;
	for(int i = 0;i<n;i++)
	{
		int product = a[i] * no + carry;
		a[i] = product%10;
		carry = product/10;
	}

	// Suppose last carry was 299
	// We have to handle this carry
	while(carry)
	{
		a[n] = carry%10;
		carry/=10;
		n++;
	}
}

void BigFactorial(int number)
{
	// Assuming that ans contains at max 1000 digits. All positions are initially zer0
	int *a = new int[1000]{0};
	a[0] = 1;
	int n = 1;

	for(int i=2;i<=number;i++)
		multiply(a,n,i);
	for(int i=n-1;i>=0;i--)
		cout<<a[i];
    cout<<endl;
    cout<<"digits: "<<n<<endl;
	cout<<endl;

}

int main()
{
	BigFactorial(6);
	BigFactorial(100);


}
