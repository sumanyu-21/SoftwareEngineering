# include <iostream>
# include <bits/stdc++.h>

using namespace std;

class Edge{
public:
	int src;
	int dest;
	int weight;
};


// Implementing Union Rank
class Node{
public:
	long data;
	int parent;
	int rank;
	int size;
};

vector<Edge>edges;
vector<Node>disjoint_set;

int find_set(int v)
{
	if(disjoint_set[v].parent == v)
		return v;

	// Path Compression--> All the nodes along this path will now have same parent.
	disjoint_set[v].parent =  find_set(disjoint_set[v].parent);
	return disjoint_set[v].parent;

}

void make_set(int v, int data)
{
	disjoint_set[v].parent = v;
	disjoint_set[v].data = data;
	disjoint_set[v].rank = 0;
	disjoint_set[v].size = 1;
}

void unionBySize(int a, int b)
{
	a = find_set(a);
	b = find_set(b);

	// They are present in different sets.
	if(a!=b)
	{
		if(disjoint_set[a].size<disjoint_set[b].size)
			swap(disjoint_set[a],disjoint_set[b]);

		disjoint_set[b].parent = a;
		disjoint_set[a].size+= disjoint_set[b].size;
	}
}

void unionByRank(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a!=b)
	{
		if(disjoint_set[a].rank<disjoint_set[b].rank)
			swap(a,b);

		disjoint_set[b].parent = a;
		if(disjoint_set[a].rank==disjoint_set[b].rank)
			disjoint_set[a].rank++;
	}
}


bool comp(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}

void Kruskals(int n, int e)
{
	// Sort the edges array on the basis of the weights of the edges.
	sort(edges.begin(),edges.end(),comp);
	// MST with n-1 edges.
	vector<Edge>MST;
	disjoint_set.resize(n);

	for(int i=0;i<n;i++)
		make_set(i,0);


	for(auto e:edges)
	{
		int u = e.src;
		int v = e.dest;
		int u_root = find_set(u);
		int v_root = find_set(v);

		if(u_root==v_root)
			continue;

		else
		{
			unionByRank(u_root, v_root);
			MST.push_back(e);
			if(MST.size()==n-1)
				break;
		}
	}
	int ans;
	for(int e=0;e<n-1;e++)
	{
		ans+=MST[e].weight;
	}
	cout<<ans;
}

int main()
{
	int n, e;
	cin>>n>>e;
	edges.resize(e);
	for(int i=0;i<e;i++)
	{
		int u,v,weight;
		cin>>u>>v>>weight;
		edges[i].src = u-1;
		edges[i].dest = v-1;
		edges[i].weight = weight;

	}
	Kruskals(n,e);
}
