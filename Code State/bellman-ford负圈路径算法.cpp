//bellman-ford�ɼ��㸺Ȧ
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
		if(j==V-1)cout<<"���ڸ�Ȧ"<<endl;
		if(!update)break;
	}
}//���ѳ�ʼdȫ��Ϊ0���ɼ������и�Ȧ 
