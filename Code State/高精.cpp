#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const long long ys=1e16; 
string s;
vector<long long>a;
vector<long long>b;
void zsc()
{
	for(int i=0;i<a.size();i++)cout<<a[i];
}
void jia()
{
	for(int i=0;i<min(a.size(),b.size());i++)
	{
		for(long long j=10;j!=1e17;i*=10)
		{
			
		}
	}
}
bool cp()
{
	if(a.size()>b.size())return true;
	if(a.size()<b.size())return false;
	for(int i=a.size();i>0;i--)
	{
		for(long long j=10;j!=1e17;i*=10)
		{
			if((a[i]%j)>(b[i]%j))return true;
			if((a[i]%j)<(b[i]%j))return false;
		}
	}
	return true;
}
void shuru()
{
	cin>>s;
	long long l=s.size();
	long long  ws=1,temp=0;
	for(int i=l-1;i>=0;i--)//倒着存放数据！！！ 
	{
		temp=temp*10+int(s[i]-'0');ws*=10;
		if(ws==ys)
		{
			a.push_back(temp);temp=0;ws=1;
		}
			
	}
	if(ws!=1)a.push_back(temp);
} 
int main()
{
	
	//从i+1开始存 
	//cout<<s.size();
	//for(int i=s.size()-1;i>=0;i--)cout<<s[i];
	
	reverse(a.begin(),a.end());
	vector<long long> ::iterator it=a.begin();
	for(;it!=a.end();it++)cout<<*it;
	364
	
}


