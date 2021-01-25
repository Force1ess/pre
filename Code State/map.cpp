#include <iostream>
#include<map>
using namespace std;
struct stuinfor{
	int id;
	char name[20];
};
int main()
{
	multimap<int,stuinfor>i;
	//把成绩输在.first里 
	//可typedef，按.first排序 
	int a,b;
	make_pair(a,b); 
	//类似于zip
	//lower_bound和upper_bound的方法是upper_bound-在这个元素后面的
	//lower_bound这个元素或在这个元素后面的
	//即bound是大于等于还是小于等于是由数组的排序方法决定 
	//map-不能有重复变量，可以使用[]里为关键字，返回与 关键字相同的.second
	//插入元素失败-重复
	mp["harry"]=78;
	//如无harry，直接插入，++mp[s]; 
}
