#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;
int main()
{
    /*//知识1-vector-可用sort-相当于一个动态分配的数组--iterator可能会过期由于分配了新的内存地址
    vector<int >b(10,1);
    vector<int > a(b.begin(),b.begin()+3);
b.push_back(4);
    a.assign(b.begin(),b.begin()+5);//assign会重置

    a.assign(4,2);a.pop_back();a.empty();//a.back;a.front;
    a.erase(a.begin(),a.begin()+2);//a.capacity()=a.size
    a.resize(10,9);swap(a,b);
     reverse(a.begin(),a.end());a.insert(find(a.begin(),a.end(),4),1,5);//返回值为它的地址
     reverse(a.begin(),a.end());
    for(int i=0;i<a.size();i++)cout<<a[i];
copy(a.begin(),a.end(),b.begin()+1);
//把a中的从a.begin()（包括它）到a.end()（不包括它）的元素复制到b中，从b.begin()+1的位置（包括它）开始复制，覆盖掉原有元素
     //对a中的从a.begin()（包括它）到a.end()（不包括它）的元素倒置，但不排列，如a中元素为1,3,2,4,倒置后为4,2,3,1
     */
     //知识2-set--自动去重，自动排序--无法以数组形式调用
     /*set<int>s;
     for(int i=1;i<=9;i++)
     {
         s.insert(i);
     }
      set<int>::iterator it;
      for(it=s.begin();it!=s.end();it++)
      {
          cout<<*it<<endl;
      }
      it=s.find(3);//返回值是一个迭代器
      //it=lower_bound(3);//返回大于等于3的迭代器
     // it=upper_bound(3);//分别返回大于3的迭代器
      int len=s.size();
      cout<<*s.end()<<len<<*it;
      erase(it);
      erase(len);
      erase(s.begin(),s.end());*/
      //3-map的使用：key与value的对应
     // map<int,string>a;//将int与string联系起来

	int n;
	cin>>n;
	cout<<n;

	}










