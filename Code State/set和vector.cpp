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
    /*//֪ʶ1-vector-����sort-�൱��һ����̬���������--iterator���ܻ�������ڷ������µ��ڴ��ַ
    vector<int >b(10,1);
    vector<int > a(b.begin(),b.begin()+3);
b.push_back(4);
    a.assign(b.begin(),b.begin()+5);//assign������

    a.assign(4,2);a.pop_back();a.empty();//a.back;a.front;
    a.erase(a.begin(),a.begin()+2);//a.capacity()=a.size
    a.resize(10,9);swap(a,b);
     reverse(a.begin(),a.end());a.insert(find(a.begin(),a.end(),4),1,5);//����ֵΪ���ĵ�ַ
     reverse(a.begin(),a.end());
    for(int i=0;i<a.size();i++)cout<<a[i];
copy(a.begin(),a.end(),b.begin()+1);
//��a�еĴ�a.begin()������������a.end()��������������Ԫ�ظ��Ƶ�b�У���b.begin()+1��λ�ã�����������ʼ���ƣ����ǵ�ԭ��Ԫ��
     //��a�еĴ�a.begin()������������a.end()��������������Ԫ�ص��ã��������У���a��Ԫ��Ϊ1,3,2,4,���ú�Ϊ4,2,3,1
     */
     //֪ʶ2-set--�Զ�ȥ�أ��Զ�����--�޷���������ʽ����
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
      it=s.find(3);//����ֵ��һ��������
      //it=lower_bound(3);//���ش��ڵ���3�ĵ�����
     // it=upper_bound(3);//�ֱ𷵻ش���3�ĵ�����
      int len=s.size();
      cout<<*s.end()<<len<<*it;
      erase(it);
      erase(len);
      erase(s.begin(),s.end());*/
      //3-map��ʹ�ã�key��value�Ķ�Ӧ
     // map<int,string>a;//��int��string��ϵ����

	int n;
	cin>>n;
	cout<<n;

	}










