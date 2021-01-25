#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = a; i > (b); --i)
#include<vector>
#define INF 0x3f3f3f3f
#include<map>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const int maxn = 1e9;
int dis[maxn];
int ans[maxn]={0};
struct edge{int to,val;};
void dik(int s)
{
	priority_queue<P,vector<P>,greater<P> >que;
	fill(dis,dis+maxn,INF);
	dis[s]=0;
	ans[s]=1; 
	que.push({0,s});
	while(!que.empty())
	{
		P p=que.top();que.pop();
		int v=p.second;
		if(dis[v]<p.first)continue;
		for(int i=0;i<g[v].size();i++)
	{
		edge e=g[v][i];
		if(dis[e.to]==dis[v]+e.val)ans[e.to]+=ans[v];
		if(dis[e.to]>dis[v]+e.val)
		{
			ans[e.to]=ans[v];
			dis[e.to]=dis[v]+e.val;
			que.push(dis[e.to],e.to);
		}
	}
	}
}


int main()
{
	int n;
	cout<<n<<endl;
}

