#include<iostream>
using namespace std;
int ksm(int a,int x)
{
	if(x==0)return 1;
	int ha=ksm(a,x/2);
	if(x%2==1)return ha*ha*a;
	else return ha*ha;
}
int main()
{
	cout<<ksm(2,7);
	
}
//dfs:dx={1,-1,0,0};dy={0,0,1,-1} 
