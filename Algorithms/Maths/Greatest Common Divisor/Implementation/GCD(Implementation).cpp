# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Euclid
{
	int A, B,GCD;
public:
	Euclid(int A, int B)
	{
		Euclid::A = A;
		Euclid::B = B;
	}

	int gcd(int a, int b)
	{
		// Base CAse
		if(b==0)
			return a;

		return gcd(b,a%b);
	}

	int lcm(int a, int b)
    {
        int gcd_ = gcd(a,b);
        return a/gcd_*b;
    }

	pair<int,int>extendedEuclid(int a, int b)
	{
		if(b==0)
		{
			// return value of base case : x = 1, y =0;
			GCD = a;
			return make_pair(1,0);

		}
		pair<int,int> p = extendedEuclid(b, a%b);
		int x = p.second;
		int y = p.first - (a/b)*p.second;
		return make_pair(x,y);
	}

	int moduloInverse(int a, int m)
	{
		if(gcd(a,m)==1)
		{

			pair<int,int> p = extendedEuclid(a,m);
			return (p.first + m)%m;  // TO make it positive
		}
		cout<<"Modulo Inverse does not exist.";
		return -1;
	}


};




int main()
{
	Euclid ob(18,30);
	cout<<ob.gcd(18,30)<<endl;
	cout<<ob.lcm(18,30)<<endl;
	pair<int,int>p = ob.extendedEuclid(18,30);
	cout<<p.first<<" "<<p.second<<endl;

	cout<<ob.moduloInverse(6,7)<<endl; // Modulo Mu
	cout<<ob.moduloInverse(18,7)<<endl;
    cout<<ob.moduloInverse(90,38)<<endl;
}
