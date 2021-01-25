#include<iostream>
typedef long long ll;
#include<queue>
#include<algorithm>
#include<cstring>
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = a; i > (b); --i)
#include<vector>
using namespace std;
int sx,sy;
int map[5][5];
int goal[5][5]={{1,1,1,1,1},{0,1,1,1,1},{0,0,2,1,1},{0,0,0,0,1},{0,0,0,0,0}};
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
int h()
{
	int fa=0;
	rep(i,0,5)
	rep(j,0,5)
	if(goal[i][j]!=map[i][j])fa++;
	return fa;
}
bool ddjs(int sx,int sy,int maxd,int d)
{
	int dh=h();
	if(dh==0)return true;
	if(dh+d-1>maxd)return false;//剪枝 
	rep(i,0,8)
	{
		int nx=sx+dx[i];
		int ny=sy+dy[i];//看了那么久，错在了dy，唉 
		if(nx>4||nx<0||ny>4||ny<0)continue;
		swap(map[nx][ny],map[sx][sy]);
		if(ddjs(nx,ny,maxd,d+1))return true;
		swap(map[nx][ny],map[sx][sy]);//回溯法，让我们再来一次！ 
	}
	return false;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		char s[10];
		rep(i,0,5)
		{
			cin>>s;
			rep(j,0,5)
			{
				if(s[j]=='0'||s[j]=='1')
				map[i][j]=s[j]-'0';
				if(s[j]=='*')
				{map[i][j]=2;
				sx=i;sy=j;
				}
			}
		}
		int f=1;
		for(;f<16;f++)
		{
			if(ddjs(sx,sy,f,0))
			{
				break;
			}
		}
		if(f<16)cout<<f<<endl;
		else cout<<-1<<endl;
		
	}
}






