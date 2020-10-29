# include <iostream>
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;

class Graph{
	// Make private Data member.
	int v;
	vector<list<int>>adjList; // Can't initialise it here.



public:
    Graph(int v) // Constructor
	{
		Graph::v = v;
		adjList.resize(v);
	}
	void addEdge(int u, int v, bool bidir=true)
	{
		if(bidir)
		{
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		else
			adjList[u].push_back(v);
	}

	void printAdjList()
	{
		for(int i=0;i<v;i++)
		{
			cout<<i<<"-->";
			for(int node:adjList[i])
			{
				cout<<node<<",";
			}
			cout<<endl;
		}
	}
};

template<typename T>
class Graph2{

	unordered_map<T, list<T> >adjList;

public:
	Graph2(){

	}

	void addEdge(T u, T v, bool bidir=true)
	{
		adjList[u].push_back(v);
		if(bidir)
			adjList[v].push_back(u);
	}

	void printAdjList()
	{
		for(auto row:adjList)
		{
			// Every row is a pair.(Row is not an iterator but a pair)
            cout<<row.first<<"-->";
			T key = row.first;
			for(auto node:row.second)
				cout<<node<<",";
            cout<<endl;
		}

	}
};
int main()
{
	/*int v;
	cin>>v;
	Graph graph(v);
	graph.addEdge(0,1);
	graph.addEdge(1,2);
	graph.addEdge(0,3);
	graph.addEdge(1,3);
	graph.addEdge(3,2);

	graph.printAdjList();*/

	Graph2<string> g;
	g.addEdge("Amritsar", "Delhi");
	g.addEdge("Amritsar", "Jaipur");
	g.addEdge("Delhi","Siachen");
	g.addEdge("Delhi","Banglore");
	g.addEdge("Delhi","Agra");
	g.addEdge("Amritsar","Siachen");
	g.printAdjList();

}
