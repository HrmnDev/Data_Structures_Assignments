// Breadth first search -BFS
#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph
{	public:
	int V;
	list <int> *l; // creation of a dynamic array 
	public:
		Graph(int V)
		{
			this->V=V;
			l=new list<int> [V]; // new list creation , size=V
		}
		void Edge(int u,int v)
		{
			l[u].push_back(v); //linking the u <-> v
			l[v].push_back(u);
		}
		void print()
		{
			for(int i=0;i<V;i++)
			{
				cout<<i<<"->";
				for(int j : l[i])   // this traverses theorugh the entire list at i th index..
				{
					cout<<j<<" ";
				}
				cout<<endl;
			}
		}	
		// BFs
		// for execution of bfs we need :- A queue to store the vertex values , a array to store the marked vertex and finally we print it
	void bfs()
	{
		queue <int> Q;
		char arr[V];
		Q.push(0);
		arr[0]='Y';
		while(Q.size()>0)
		{
			int u=Q.front();
			
			Q.pop();
			cout<<u<<" ";
			
			for(int v:l[u])// v stores all the neighbours of u
			{
				if(arr[v]!='Y')
				{
					{
						arr[v]='Y';
						Q.push(v);
					}
				}
			}
		}
		
	}
};
int main ()
{
	Graph g(5);
	g.Edge(0,1);
	g.Edge(1,3);
	g.Edge(1,2);
	g.Edge(2,4);
	g.Edge(2,3);
	g.print();
	g.bfs();
	system("pause");
}
