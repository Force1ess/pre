//bellman-ford可计算负圈
#include<bits/stdc++.h>
const int maxn=1e6,INF=1e7
using namespace std;
struct edge
{
	int from,to,cost;
}
edge es[maxn];
int d[maxn],V,E;
void s_path(int s)
{
	for(int i=0;i<V;i++)d[i]=INF;
	d[s]=0;
	for(int j=0;j<V;j++)
	{
		bool update=false;
		for(int i=0;i<E;i++)
		{
			edge e=es[i];
			if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost)
			{
				d[e.to]=d[e.from]+e.cost;
				update=true;
			}
		}
		if(j==V-1)cout<<"存在负圈"<<endl;
		if(!update)break;
	}
}//若把初始d全设为0，可检测出所有负圈 
