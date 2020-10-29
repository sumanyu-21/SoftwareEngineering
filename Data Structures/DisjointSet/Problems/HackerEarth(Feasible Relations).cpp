# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int rank;
	int parent;
};

vector<Node>disjointSet;

void makeSet(int i)
{
	disjointSet[i].rank = 0;
	disjointSet[i].parent = i;
}

int findSet(int u)
{
	if(disjointSet[u].parent==u)
		return u;

	// Path Compression.
	disjointSet[u].parent = findSet(disjointSet[u].parent);
	return disjointSet[u].parent;
}

void unionByRank(int u, int v)
{
	u = findSet(u);
	v = findSet(v);

	if(u!=v)
	{
		if(disjointSet[u].rank<disjointSet[v].rank)
			swap(u,v);

		disjointSet[v].parent = u;

		if(disjointSet[u].rank==disjointSet[v].rank)
			disjointSet[u].rank+=1;

	}

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		disjointSet.clear();
		disjointSet.resize(n+1);
		for(int i=1;i<=n;i++)
			makeSet(i);

		vector<pair<int,int> >not_edges;
		for(int i=0;i<k;i++)
		{
		    int a, b;
		    string op;
		    cin>>a>>op>>b;
			if(op=="=")
                unionByRank(a,b);

			else
				not_edges.push_back(make_pair(a,b));
		}

		for(auto p:not_edges)
		{
			if(findSet(p.first)==findSet(p.second))
				cout<<"NO"<<endl;

			else
				cout<<"YES"<<endl;
		}
	}
}
