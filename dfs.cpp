//Actually depth first search is implemented using stack but here recursion take cares of it
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(c) (c).begin(),(c).end()
#define tr(container, it) \
	for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define cpresent()
vi V;
void dfs(const vvi &adj,int i)//DFS CODE
{
	if(!V[i])
	{
		V[i]=1;
		tr(adj[i],it)
			dfs(adj,*it);
	}
}
int main()
{
	int vertices,edges;
	cin>>vertices>>edges;
	int v1,v2;
	V.resize(vertices+1);//visited array initialised to unvisited
	vvi adj(vertices+1);//adjacency list
	for(int i=0;i<edges;++i)
	{
		cin>>v1>>v2;
		adj[v1].push_back(v2);
	}
	for(int i=0;i<adj.size();++i)
	{
		printf("adj[%d]->",i);
		tr(adj[i],it)
		{
			printf("%d,",(*it));
		}
		printf("\n");
	}
	dfs(adj,1);
	//tr(V,it)
	//	cout<<(*it)<<" "<<endl;
	if(find(V.begin()+1,V.end(),0)==V.end())
		cout<<"Connected\n";
	else
		cout<<"Not connected\n";
	return 0;
}
