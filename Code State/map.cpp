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
	//�ѳɼ�����.first�� 
	//��typedef����.first���� 
	int a,b;
	make_pair(a,b); 
	//������zip
	//lower_bound��upper_bound�ķ�����upper_bound-�����Ԫ�غ����
	//lower_bound���Ԫ�ػ������Ԫ�غ����
	//��bound�Ǵ��ڵ��ڻ���С�ڵ���������������򷽷����� 
	//map-�������ظ�����������ʹ��[]��Ϊ�ؼ��֣������� �ؼ�����ͬ��.second
	//����Ԫ��ʧ��-�ظ�
	mp["harry"]=78;
	//����harry��ֱ�Ӳ��룬++mp[s]; 
}
