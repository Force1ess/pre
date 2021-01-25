#include<bits/stdc++.h>
using namespace std;
struct edge{int u,v,cos};
const int maxn=1000;
int rank[maxn],par[maxn];
void ini(int n)
{
	for(int i=0;i<n;i++)rank[i]=0,par[i]=i;
	return ;
}
int find(int i)
{
	if(par[i]==i)return i;
	else return find(par[i]);
}
bool same(int i,int j)
{
	if(find(i)==find(j))return true;
	return false;
 } 
void unite(int i,int j)
{
	i=find(i);j=find(j);
	if(i==j)return;
	if(rank[i]<rank[j])par[i]=j;
	else par[j]=i;
	if(rank[i]==rank[j])rank[i]++;
	return;
}
bool comp(edge e1,edge e2)
{
	return e1.cos>e2.cos;
}
int main()
{
		int res=0,n;cin>>0;
		ini(n);
		for(int i=0;i<E;i++)
		{
			edge e=es[i];
			if(!same(e.u,e.v))
			{
				unite(e.u,e.v);
				res+=e.cos;
			}
		}
} 
//priM算法类似迪科斯彻 
