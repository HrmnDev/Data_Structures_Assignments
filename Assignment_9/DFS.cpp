// Breadth first search -BFS
#include<iostream>
#include<list>
#include<queue>

using namespace std;
class Graph
{	public:
	int V;
	list <int> *l;
	public:
		Graph(int V)
		{
			this->V=V;
			l=new list<int> [V]; 
		}
		void Edge(int u,int v)
		{
			l[u].push_back(v); 
			l[v].push_back(u);
		}
		void print()
		{
			for(int i=0;i<V;i++)
			{
				cout<<i<<"->";
				for(int j : l[i])
				{
					cout<<j<<" ";
				}
				cout<<endl;
			}
		}	

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
			
			for(int v:l[u])
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
	void dfs_main(int u,char arr[])
	{
		cout<<u<<" ";
		arr[u]='Y';
		for(int v:l[u])
		{
			if(arr[v]!='Y')
			{
				dfs_main(v,arr);
			}
		}
	}
	void dfs_base()
	{
	    int src=0;
	    char arr[V];
	    dfs_main(src,arr);
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
	cout<<"The bfs is:";
	g.bfs();
	cout<<endl<<"the dfs is:";
	g.dfs_base();

}
