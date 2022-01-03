#include<iostream>
using namespace std;
int head[100000],cnt;
long long ans[1000000];
bool vis[1000000];
int n=12,m=7,s,z;
int graph[12][3]={{0,1,4},{0,2,6},{0,3,6},{1,2,1},{1,4,7},{3,2,2},{3,5,5},{2,4,6},{2,5,4},{5,4,1},{5,6,8},{4,6,6}};
struct edge
{
	int to;
	int nextt;
	int wei;
}edge[1000000];
void addedge(int x,int y,int z)
{
	edge[++cnt].to=y;
	edge[cnt].wei=z;
	edge[cnt].nextt=head[x];
	head[x]=cnt;
}
int main()
{
    cout<<"请输入起点、终点:"<<endl;
	cin>>s>>z;
	for(int i=1;i<=n;i++)
	{
		ans[i]=2147483647;
	}
	ans[s]=0;
	for(int i=1;i<=n;i++)
	{
		addedge(graph[i-1][0],graph[i-1][1],graph[i-1][2]);
	}
	int pos=s;
	while(vis[pos]==0)
	{
		long long minn=2147483647;
		vis[pos]=1;
		for(int i=head[pos];i!=0;i=edge[i].nextt)
		{
			if(!vis[edge[i].to]&&ans[edge[i].to]>ans[pos]+edge[i].wei)
			{
				ans[edge[i].to]=ans[pos]+edge[i].wei;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(ans[i]<minn&&vis[i]==0)
			{
				minn=ans[i];
				pos=i;
			}
		}
	}
    cout << "寻路结果（即输入的起点和终点的最短路径）:";
	cout<<ans[z]<<' ';
}