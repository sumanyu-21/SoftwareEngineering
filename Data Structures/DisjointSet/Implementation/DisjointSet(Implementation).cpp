# include <iostream>
# include <bits/stdc++.h>

using namespace std;

class Node{
public:
	long data;
	int parent;
	int rank;
	int size;
}
vector<Node>set;

int find_set(int v)
{
	if(set[v].parent == v)
		return v;

	// Path Compression--> All the nodes along this path will now have same parent.
	set[v].parent =  find_set(set[v].parent);
	return set[v].parent;

}

void make_set(int v, int data)
{
	set[v].parent = v;
	set[v].data = data;
	set[v].rank = 0;
	set[v].size = 1;
}

void unionBySize(int a, int b)
{
	a = find_set(a);
	b = find_set(b);

	// They are present in different sets.
	if(a!=b)
	{
		if(set[a].size<set[b].size)
			swap(a,b);

		set[b].parent = a;
		set[a].size+= set[b].size;
	}
}

void unionByRank(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a!=b)
	{
		if(set[a].rank<set[b].rank)
			swap(a, b)

		set[b].parent = a;
		if(set[a].rank==set[b].rank)
			set[a].rank++;
	}
}


int main()
{

}