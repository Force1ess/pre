#include<iostream>
#include<vector>
#define pb push_back
using namespace std;
int cnt=0;
vector<int>a;
void oula(int x)
{
	a.pb(2);++cnt;
	bool * f=new bool [x+1];
	fill(f,f+x+1,true);
	for(int i=3;i<x;i+=2)
	{
		if(f[i]){a.pb(i);cnt++;}
		for(int j=1;j<=cnt;j++)
		{
			if(a[j]*i>x)break;
			f[i*a[j]]=false;
			if(i%a[j]==0)break;
		}
	}
	return;
}
int main()
{
	int x;cin>>x;
	oula(x);
	for(int i=1;i<cnt;i++)cout<<a[i]<<endl;
 } 
 //偶数位回文数必定不是质数 
 //1e9
 //1e6级别的Int即为1mb 
