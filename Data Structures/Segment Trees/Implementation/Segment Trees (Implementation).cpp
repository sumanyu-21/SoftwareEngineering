# include <iostream>
# include <stdio.h>

using namespace std;

class QueryInterface()
{
public:

	virtual void increment(int i, int j, int val);
	virtual int minimum(int i, int j);
};

class RangeSlow:public QueryInterface
{
	vector<int>arr;
	int n;
public:
	RangeSlow(int n)
	{
		RangeSlow::n = n;
		arr.resize(n);
	}

	void increment(int i, int j, int val)
	{
		for(int k=i;k<=j;k++)
			arr[k]+=val;
	}

	int minimum(int i, int j)
	{
		int res = arr[i];
		for(int k=i+1;k<=j;k++)
			res = min(res, arr[k])
	}


};

class SegmentTree:public QueryInterface
{
	int n;
	vector<int>low ,high; // Tells us the range each index in segment tree is responsible for
	vector<int>arr;
	vector<int>s_t; // Segment Tree.
	vector<int>d_t; //Propagation Tree
public:
	SegmentTree(int n)
	{
		SegmentTree::n = n;
		low.resize(4*n+1);
		high.resize(4*n+1);
		arr.resize(4*n+1);
		d_t.resize(4*n+1);
		s_t.resize(4*n+1);

		init(0, 0, n-1);
	}

	void prop(int i)
	{
		// Push d_t change down to children;
		d_t[2*i+1] += d_t[i];
		d_t[2*i+2] += d_t[i];

		// Resetting d_t of parent to 0;
		d_t[i] = 0;

	}

	void update(int i)
	{
		// Update the minimum in range.
		s_t[i] = min(s_t[2*i+1] + d_t[2*i+1], s_t[2*i+2] + d_t[2*i+2]);
	}

	void increment(int i, int a, int b, int val)
	{
		// (1) Whenever we start touching a node, we have to push down changes down the node.
		// (2) Whenever we are done with a node, we have to aggregate changes upwards.

		// No overlap
		// a-----b  low[i]------high[i]
		if(b<low[i] || high[i]<a)
			return;

		// Complete Overlap
		if(a<=low[i] && high[i]<=b)
		{
			// We do not need to propagate any changes down to children.
			d_t[i]+=val;
			return;
		}

		// (1) Partial Overlap;
		prop(i); // Push Changes down to children;
		increment(2*i+1, a, b, val);
		increment(2*i*2, a, b, val);

		// (2) Coming back from recursion;
		update(i);

	}

	int minimum(int i, int a, int b)
	{
		if(b<low[i] || high[i]<a)
			return INT_MAX;

		if(a<=low[i] && high[i]<=b)
			return s_t[i] + d_t[i];

		// Partial Overlap
		prop(i);
		int minLeft = min(2*i+1, a, b);
		int minRight = min(2*i+2, a, b);

		// We do not update the s_t[i] using minLeft and minRight because
		// these are partial overlaps and hence the s_t[i] will not correspond to min(minLeft, minRight);
		update(i);

		// Note: we don't want to return s_t[i] because that corresponds to the entire range in ith node.
		return min(minLeft, minRight);
	}
	void init(int i, int a, int b)
	{

		low[i] = a;
		high[i] = b;

		if(a==b)
			return;
	
		int mid = (a+b)/2;
		init(2*i+1, a, mid); // For this case, a<=b; Not to worry but this.
		init(2*i+2, mid+1, b); // For this mid+1>b only when a==b. However we handled this in return statement. Not to worry about this too.
	}

}

int main()
{

}