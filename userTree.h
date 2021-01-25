#pragma once
#include<iostream>
using namespace std;
class node
{
public:
	node* left = 0;
	node* right = 0;
	string userId;
	string userPassword;
	node() :right(0), left(0) {};
	node(string a, string b) :userId(a), userPassword(b), right(0), left(0) {};
};
class userTree
{
private:
	node* root;
	void insert(string id, string pass, node*& p); //���ڲ������û����ݣ��ݹ���,a������
	void Delete(string name, node*& a);//�ݹ���
	node* FindMin(node* a);//ɾ����
	void graphAux(int n, node* root);
public:
	node* r_ro(node* a);//����,������ƽ��ڵ�
	node* l_ro(node* a);//������������ƽ��ڵ�
	node* lr_ro(node* a);//������
	node* rl_ro(node* a);//������
	void insert(string id, string pass);//����������û����ݣ��ж��Ƿ��ظ��û���
	int depth(node* a);//�ڵ�������ȣ�Ҷ��Ϊ1�����ϵ��������ڼ���ƽ������
	void Delete(string name);
	void graph();
	userTree() :root(0) {};
	node* search(string name);
	friend ostream& operator << (ostream& stream, userTree a);  //����ļ� 
	friend void outtxt(node* a, ostream& output);
	void show(node* a); 
	void show();
};