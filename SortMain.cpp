#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include "bst.h"
#include <windows.h>
using namespace std;
#define num 100
template <class T>
void ResetData(vector<T>& x, vector<T>& y); //ʹ��y����x
template <class T>
void BubbleSort(vector<T>& x)
{
	for (int i = 1; i < x.size(); i++)
	{
		for (int j = i; j < x.size(); j++)
		{
			if (x[i] > x[j])swap(x[i], x[j]);
		}
	}
}

template <class T>
void SelectSort(vector<T>& x) //ѡ������
{
	for (int i = 1; i < x.size(); i++)
	{
		int l = i;
		for (int j = i; j < x.size(); j++)
		{
			if (x[l] > x[j])l = j;
		}
		swap(x[l], x[i]);
	}
}

template <class T>
void InsertSort(vector<T>& x) //��������
{
	for (int i = 1; i < x.size(); i++)
	{
		int j = i;
		while (j > 0 && x[j] < x[j - 1])
		{
			swap(x[j], x[j - 1]);
			j--;
		}
	}
}

template <class T>
void ShellSort(vector<T>& x) //ϣ������
{
	for (int gap = x.size() / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < x.size(); i++)
		{
			int j = i;
			while (j - gap >= 0 && x[j] < x[j - gap])
			{
				swap(x[j], x[j - gap]);
				j -= gap;
			}
		}
	}
}

template <class T>
void CountedSort(vector<T>& x) //��������
{
	T ma = x[1];
	for (int i = 1; i < x.size(); i++)
	{
		ma = max(ma, x[i]);
	}
	vector<T> co(ma + 2);
	for (int i = 1; i < x.size(); i++)
	{
		co[x[i]]++;
	}
	int ind = 1;
	for (int i = 0; i < co.size() - 1; i++)
	{
		while (co[i] > 0)
		{
			x[ind++] = i;
			co[i]--;
		}
	}
}

template <class T>
void RadixSort(vector<T>& x) //��������
{
	T ma=-99;
	for (T i : x) {
		ma = max(i, ma);
	}
	int d = 0;
	while (ma > 0) {
		ma /= 10;
		++d;
	}
	int n = x.size();
	vector<int> tem(n);
	vector<int> co(10);
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) {
		for (j = 0; j < 10; j++)
			co[j] = 0;
		for (j = 0; j < n; j++) {
			k = (x[j] / radix) % 10;
			co[k]++;
		}
		for (j = 1; j < 10; j++) {
			co[j] = co[j - 1] + co[j];
		}
		for (j = n - 1; j >= 0; j--) {
			k = (x[j] / radix) % 10;
			tem[co[k] - 1] = x[j];
			co[k]--;
		}
		x = tem;
		radix *= 10;
	}
}

template <class T>
void BSTSort(vector<T>& x)
{
	BST<T> bst;
	for(int i=1;i<x.size();i++)
	{
		bst.insert(x[i]);
	}
	x = bst.pr();
	reverse(x.begin()+1, x.end());
}

//�������������
template <class T>
int partition(vector<T>& x, int st, int en)
{
	int tmp = x[st];
	while (st < en)
	{
		while (st < en && x[en] >= tmp) { en--; }
		x[st] = x[en];
		while (st < en && x[st] <= tmp) { st++; }
		x[en] = x[st];
	}
	x[st] = tmp;
	return st;
}

template <class T>
void QuickSort(vector<T>& x, int st, int en) //��������
{
	if (st >= en)return; //������ĳ���Ϊ0������,����Ϊ>=��en����С��st��
	int i = partition(x, st, en); //���б�i������󣬱�iС������
	QuickSort(x, st, i - 1); //��i��λ�������ң��Ѿ�����
	QuickSort(x, st + 1, en);
}

template <class T>
void adjustHeap(vector<T>& x, int i, int len)
{
	int tem = x[i];
	for (int k = 2 * i + 1; k < len; k *= 2 + 1)
	{
		if (k + 1 < len && x[k] < x[k + 1])
		{
			k++;
		}
		if (x[k] > tem)
		{
			x[i] = x[k];
			i = k;
		}
		else
		{
			break;
		}
	}
	x[i] = tem;
}

template <class T>
void HeapSort(vector<T>& x)
{
	for (int i = x.size() - 1; i >= 0; i--)
	{
		adjustHeap(x, i, x.size());
	}
	for (int j = x.size() - 1; j > 0; j--)
	{
		swap(x[0], x[j]);
		adjustHeap(x, 0, j);
	}
}
class Wait
{
	LARGE_INTEGER begin;
	LARGE_INTEGER end;
	LARGE_INTEGER cpu;

public:
	Wait()
	{
		QueryPerformanceFrequency(&cpu);
	}
	void start() {
		QueryPerformanceCounter(&begin);
	}
	double stop() {
		QueryPerformanceCounter(&end);
		double time = (static_cast<double>(end.QuadPart) - static_cast<double>(begin.QuadPart)) / static_cast<double>(cpu.QuadPart);
		cout << "�㷨��ʱ:" << time * 1000 <<"ms"<< endl;
		return time;
	}
};
template <class T>
void Display(vector<T>& x);
//......�������������Ҫ�ĺ�������
int main()
{
	vector<int> a(num + 1), b(num + 1);
	//��Ч���ݴ�1��ʼ��Ҳ������ƴ�0��ʼ�����и�����Ҫ����
	int i;
	double tim;
	srand(time(0)); //��������ӳ�ʼ��
	Wait wa;
	for (i = 1; i <= num; i++)
	{
		a[i] = rand() % 10000 + 1; //�������1-10000�ڵ���ֵ��Ϊ�������
		b[i] = a[i];
	}
	//����ǰ��ʾ����
	cout << "����ǰ" << endl;
	Display(a);
	//ð������
	wa.start();
	BubbleSort(a);
	wa.stop();
	cout << "ð�������" << endl;
	Display(a);
	//ѡ������
	ResetData(a, b);
	wa.start();
	SelectSort(a);
	wa.stop();
	cout << "ѡ�������" << endl;
	Display(a);
	//��������
	ResetData(a, b);
	wa.start();
	InsertSort(a);
	wa.stop();
	cout << "���������" << endl;
	Display(a);
	//ϣ������
	ResetData(a, b);
	wa.start();
	ShellSort(a);
	wa.stop();
	cout << "ϣ�������" << endl;
	Display(a);
	////��������
	ResetData(a, b);
	wa.start();
	CountedSort(a);
	wa.stop();
	cout << "���������" << endl;
	Display(a);
	//��������
	ResetData(a, b);
	wa.start();
	RadixSort(a);
	wa.stop();
	cout << "���������" << endl;
	Display(a);
	//�����Ʒ��BST����
	ResetData(a, b);
	wa.start();
	BSTSort(a);
	wa.stop();
	cout << "BST�����" << endl;
	Display(a);
	//��������
	ResetData(a, b);
	wa.start();
	QuickSort(a, 1,num);
	wa.stop();
	cout << "���������" << endl;
	Display(a);
	//������
	ResetData(a, b);
	wa.start();
	HeapSort(a);
	wa.stop();
	cout << "�������" << endl;
	Display(a);
	
}

template <class T>
void Display(vector<T>& x)
{
	for (int i = 1; i <=num; i++)
	{
		cout << x[i] << " ";
		if (i % 15 == 0) cout << endl;
	}
}

template <class T>
void ResetData(vector<T>& x, vector<T>& y) //ʹ��y����x
{
	for (int i = 1; i <= num; i++)
	{
		x[i] = y[i];
	}
}
