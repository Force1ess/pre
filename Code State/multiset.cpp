#include<iostream>
#include<algorithm>
#include<set>
#include<map> 
using namespace std;
struct ru1{
	bool operator ()(const int& a,const int& b)const
	{
		return a>b;
	}
};
int main()
{
multiset<int>s;
s.insert(2);
multiset<int>::iterator i;//相当于int * i;
i=s.begin();
s.find(3);//找不到也会返回s.end()
//if s.find(2)==s.end()没找到
i=s.lower_bound(1);
i=s.upper_bound(2); 
s.erase(i);
multiset<int,ru1>;
//find时，也是根据ru1来查找
set <int >::iterator
//set不允许重复，但multiset可以
pair(set<int >::iterator,bool) result=s.insert(2);
if(result.second)cout"ok";
//pair相当于定义了一个结构体变量，类型为提供的两个，名字为first和second
//insert可能失败
//multimap里的元素都是pair型的
multimap<int,bool>mp;
//默认按照.first<.first来排序	
//头文件map 
}
