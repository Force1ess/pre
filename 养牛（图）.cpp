#include<iostream>
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = a; i > (b); --i)
using namespace std;
const int maxn=10010;
int al[maxn],bl[maxn],dl[maxn];
int ad[maxn],bd[maxn],dd[maxn];
int n,ml,md;
const int inf=1010000;
int d[1010];
void bellman_ford()
{
    fill(d+1,d+1010,inf);
    d[1]=0;
    rep(k,0,n)
    {
        rep(i,1,n )if(d[i+1]<inf)d[i]=min(d[i+1],d[i]);
        rep(i,0,ml)
        {
            if(d[al[i]]<inf)d[bl[i]]=min(d[bl[i]],d[al[i]]+dl[i]);
        }
        rep(i,0,md)
        {
            if(d[bd[i]]<inf)d[ad[i]]=min(d[ad[i]],d[bd[i]]-dd[i]);
        }
    }
    return;
}
int main()
{
    
    cin>>n>>ml>>md;
    rep(i,0,ml)cin>>al[i]>>bl[i]>>dl[i];
    rep(i,0,md)cin>>ad[i]>>bd[i]>>dd[i];
    bellman_ford();
    int res=d[n];
    if(d[1]<0)cout<<-1<<endl;
    else if(res==inf)cout<<-2<<endl;
    else cout<<res<<endl;
}