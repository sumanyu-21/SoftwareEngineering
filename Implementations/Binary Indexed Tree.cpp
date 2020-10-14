# include <iostream>
# include <stdio.h>
using namespace std;
// Elements in Fenwick Tree are stored from index 0.

class BIT
{
	int n;
	vector<int>fenwick;
	
	public:
		BIT(int n)
		{
			BIT::n = n
			fenwick.resize(n+1);
		}

		void update(int i, int delta)
		{
			'''Update all the cells bing affected by ith cell.'''

			while(i<fenwick.size())
			{
				fenwick[i] += delta;
				i += (i&(-i)) //We are moving up the tree.
			}
		}

		int sum(int i)
		{
			''' Compute the prefic sum value in range[1,i]'''
			int sum = 0;
			while(i>0)
			{
				sum += fenwick[i];
				i -= (i&(-i)); // Going down the subtree.
			}
		}

		int rangeSum(int l, int r)
		{
			'''Compute the range sum in the given range'''
			return  sum(r) - sum(l-1);
		}
};

