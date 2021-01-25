#include<bits/stdc++.h>
using namespace std;
const int maxn=50000;
int rank[3*maxn+100],par[3*maxn+100],T[maxn],X[maxn],Y[maxn];
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
int main()
{
	int n,k;cin>>n>>k;int ans=0;init(3*n+100);
	for(int i=0;i<k;i++)cin>>T[i]>>X[i]>>Y[i];
	for(int i=0;i<k;i++)
	{
		int x=X[i]-1,y=Y[i]-1,t=T[i];
		if(x>=n||y>=n||x<0||y<0){ans++;continue;}
		if(t==1)
		{
			
			if(same(x,y+n)||same(x,y+2*n)){ans++;continue;}
			else
			{
				unite(x,y);
			}
		}
		else
		{
			if(x==y){ans++;continue;}
			if(same(x,y)||same(x,y+2*n)){ans++;continue;}
			else 
			{
				unite(x,y+n);
			}
		}
	}
	cout<<ans<<endl;
}



