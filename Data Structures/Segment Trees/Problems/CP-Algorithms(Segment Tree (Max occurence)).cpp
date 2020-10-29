# include <iostream>
# include <stdio.h>

class SegmentTree
{
	int n;
	vector<int>low, high, d_t, s_t;
public:
	SegmentTree(int n)
	{
		SegmentTree::n = n;
		low.resize(4*n+1);
		high.resize(4*n+1);
		d_t.resize(4*n+1);
		s_t.resize(4*n+1);
	}

	
}

using namespace std;
int main()
{

}