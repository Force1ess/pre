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
	void insert(string id, string pass, node*& p); //对内插入新用户数据，递归用,a用引用
	void Delete(string name, node*& a);//递归用
	node* FindMin(node* a);//删除用
	void graphAux(int n, node* root);
public:
	node* r_ro(node* a);//右旋,返回新平衡节点
	node* l_ro(node* a);//左旋，返回新平衡节点
	node* lr_ro(node* a);//左右旋
	node* rl_ro(node* a);//右左旋
	void insert(string id, string pass);//对外插入新用户数据，判断是否重复用户名
	int depth(node* a);//节点所在深度，叶子为1，向上递增，用于计算平衡因子
	void Delete(string name);
	void graph();
	userTree() :root(0) {};
	node* search(string name);
	friend ostream& operator << (ostream& stream, userTree a);  //输出文件 
	friend void outtxt(node* a, ostream& output);
	void show(node* a); 
	void show();
};