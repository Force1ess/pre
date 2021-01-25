#include<iostream>
using namespace std;
int partition(int arr[],int st ,int en)
{
	int tmp = arr[st];
	while (st < en)
	{
		while (st < en && arr[en] >= tmp) { en--; }
		arr[st] = arr[en];
		while (st < en && arr[st] <= tmp) { st++; }
		arr[en] = arr[st];
	}
	arr[st] = tmp;
	return st;
}
void quick_sort(int arr[], int st,int en)
{
	if (st >= en)return;//������ĳ���Ϊ0������,����Ϊ>=��en����С��st��
	int i= partition(arr,st,en);//���б�i������󣬱�iС������
	quick_sort(arr, st, i-1);//��i��λ�������ң��Ѿ�����
	quick_sort(arr, st + 1, en);
}
int main()
{
	int a[4] = { 9, 123, 321, 99 };
	quick_sort(a, 0, 3);
	for (auto i : a)cout << i << endl;
}