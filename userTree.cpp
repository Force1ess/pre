#include "userTree.h"
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
node* userTree::r_ro(node* a)//aָ��ƽ������2�ĵ㣬������ɺ󷵻���ƽ���
{
	node* r = a->left;         
	a->left = r->right;                   
	r->right = a;
	return r;
}
//��a��������r��Ϊ�ŵ�a��λ�ã�a���ӳ�Ϊr����������rԭ�е���������Ϊa��������
node* userTree::l_ro(node* a)//����ͬ��
{
	node* r = a->right;
	a->right = r->left;
	r->left = a;
	return r;
}
//��a��������r�ŵ�a��λ�ã�a���ӵ�r����������rԭ�е���������Ϊa��������
node* userTree::lr_ro(node* a)
{
	a->left = l_ro(a->left);
	return r_ro(a);
}
//��������������������a��ƽ������Ϊ2�ĵ�
node* userTree::rl_ro(node* a)
{
	a->right = r_ro(a->right);
	return l_ro(a);
}
//��������������������a��ƽ������Ϊ-2�ĵ�
void userTree::insert(string id, string pass)
{
	int found = 0;
	//����Ƿ��ظ�
	node* ptr = root;
	while (ptr != 0 && !found)
	{
		if (id > ptr->userId)
			ptr = ptr->right;
		else if (id < ptr->userId)
			ptr = ptr->left;
		else
			found = 1;
	}
	if (found)
	{
		cout << "����ʧ�ܣ����û����ѱ�ռ��" << endl;
		return;
	}
	insert(id, pass, root);
}
void userTree::insert(string id, string pass, node*& p)
{
	if (p == 0)p = new node(id, pass);
	else if (id > p->userId)
	{
		insert(id, pass, p->right);
		if (depth(p->right) - depth(p->left) > 1)//ƽ��״̬�������ҽڵ㣬�Ҹ߼���߿϶����ڵ���0   //��ת��ƽ��
		{
			if (id > p->right->userId)       //�������������
				p = l_ro(p);
			if (id < p->right->userId)       //���������������
				p = rl_ro(p);
		}
	}
	else
	{
		insert(id, pass, p->left);
		if (depth(p->left) - depth(p->right) > 1)
		{
			if (id < p->left->userId)            //��������
				p = r_ro(p);
			if (id > p->left->userId)            //���ң�������
				p = lr_ro(p);
		}
	}
}
int userTree::depth(node* a)//�ݹ������
{
	if (a == NULL)
		return 0;
	return max(depth(a->left), depth(a->right)) + 1;
}
void userTree::Delete(string name)
{
	int found = 0;
	node* ptr = root;
	while (ptr != 0 && !found)
	{
		if (name > ptr->userId)
			ptr = ptr->right;
		else if (name < ptr->userId)
			ptr = ptr->left;
		else
			found = 1;
	}
	if (!found)
	{
		cout << "ɾ��ʧ�ܣ����û�δע��!" << endl;
		return;
	}
	Delete(name, root);
}
void userTree::Delete(string name, node*& a)
{
	if (a == NULL)
		return;
	else if (name > a->userId)  //��ƽ
	{
		Delete(name, a->right);
		if (depth(a->left) - depth(a->right) > 1)
		{
			if (a->left->right && a->left->left)   //ɾ�������е�������������PPT
				a = r_ro(a);
			else if (a->left->right)            //���ң�˫��
				a = lr_ro(a);
			else                                //��������
				a = r_ro(a);
		}
	}
	else if (name < a->userId)   //��ƽ
	{
		Delete(name, a->left);
		if (depth(a->right) - depth(a->left) > 1)
		{
			if (a->right->right && a->right->left)   //ɾ�������е�������������PPT
				a = l_ro(a);
			else if (a->right->left)            //����˫��
				a = rl_ro(a);
			else                                //���ң�����
				a = l_ro(a);
		}
	}
	else     //ɾ��
	{
		if (a->left && a->right)   //����������
		{
			a->userId = FindMin(a->right)->userId;
			a->userPassword = FindMin(a->right)->userPassword;
			Delete(name, a->right);
		}
		else                       //ֻ��һ�����ӻ���û�к���
		{
			node* t = a;
			if (a->left == 0)
				a = a->right;
			else if (a->right == 0)
				a = a->left;
			delete t;
		}
	}
}
node* userTree::FindMin(node* a)//ɾ���в���ֱ�Ӻ��
{
	if (a == 0)
		return 0;
	else
	{
		if (a->left == 0)
			return a;
		else
			return FindMin(a->left);
	}
}
void userTree::graphAux(int n, node* root)
{
	if (root != 0)
	{
		graphAux(n + 8, root->right);
		cout << setw(n) << " " << root->userId << endl;
		graphAux(n + 8, root->left);
	}
}
void userTree::graph()
{
	graphAux( 0, root);
}

node* userTree::search(string name)
{
	node* locptr = root;
	while (locptr != 0)
	{
		if (name > locptr->userId)
			locptr = locptr->right;
		else if (name < locptr->userId)
			locptr = locptr->left;
		else
			return locptr;
	}
	return 0;
}
void outtxt(node* a, ostream& output)  //�������
{
	if (a == 0)
		return;
	output << a->userId << " " << a->userPassword << endl;
	outtxt(a->left, output);
	outtxt(a->right, output);
}
ostream& operator <<(ostream& stream, userTree a)  //����ļ������û����浽txt�� 
{
	outtxt(a.root, stream);
	return stream;
}
void userTree::show(node* a) 
{
	if (a == NULL) return;
	cout << "                   *  " << a->userId << "   " << a->userPassword << endl;
	show(a->left);
	show(a->right);
}
void userTree::show()
{
	show(root);
}