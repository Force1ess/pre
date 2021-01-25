#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int rank[maxn],par[maxn];
void init(int n)
{
	for(int i=0;i<n;i++)par[i]=i,rank[i]=0;
	return;
}
int find(int x)
{
	if(x==par[x])return x;
	else return find(par[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x==y)return;
	if(rank[x]<rank[y])par[x]=y;
	else par[y]=x;
	if(rank[x]==rank[y])rank[par[x]]++;
	return ;
}
bool same(int x,int y)
{
	if(find(x)==find(y))return true;
	return false;
}
//并查集，已知的优化方法：路径压缩 
