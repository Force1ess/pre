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
multiset<int>::iterator i;//�൱��int * i;
i=s.begin();
s.find(3);//�Ҳ���Ҳ�᷵��s.end()
//if s.find(2)==s.end()û�ҵ�
i=s.lower_bound(1);
i=s.upper_bound(2); 
s.erase(i);
multiset<int,ru1>;
//findʱ��Ҳ�Ǹ���ru1������
set <int >::iterator
//set�������ظ�����multiset����
pair(set<int >::iterator,bool) result=s.insert(2);
if(result.second)cout"ok";
//pair�൱�ڶ�����һ���ṹ�����������Ϊ�ṩ������������Ϊfirst��second
//insert����ʧ��
//multimap���Ԫ�ض���pair�͵�
multimap<int,bool>mp;
//Ĭ�ϰ���.first<.first������	
//ͷ�ļ�map 
}
