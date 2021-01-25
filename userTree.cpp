#include "userTree.h"
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
node* userTree::r_ro(node* a)//a指向平衡因子2的点，运行完成后返回新平衡点
{
	node* r = a->left;         
	a->left = r->right;                   
	r->right = a;
	return r;
}
//把a的左子树r作为放到a的位置，a连接成为r的右子树，r原有的右子树作为a的左子树
node* userTree::l_ro(node* a)//左旋同理
{
	node* r = a->right;
	a->right = r->left;
	r->left = a;
	return r;
}
//把a的右子树r放到a的位置，a连接到r的左子树，r原有的左子树成为a的右子树
node* userTree::lr_ro(node* a)
{
	a->left = l_ro(a->left);
	return r_ro(a);
}
//先左旋再右旋，右旋的a是平衡因子为2的点
node* userTree::rl_ro(node* a)
{
	a->right = r_ro(a->right);
	return l_ro(a);
}
//先右旋再左旋，左旋的a是平衡因子为-2的点
void userTree::insert(string id, string pass)
{
	int found = 0;
	//检查是否重复
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
		cout << "创建失败：该用户名已被占用" << endl;
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
		if (depth(p->right) - depth(p->left) > 1)//平衡状态下新增右节点，右高减左高肯定大于等于0   //旋转至平衡
		{
			if (id > p->right->userId)       //右右情况，左旋
				p = l_ro(p);
			if (id < p->right->userId)       //右左情况，右左旋
				p = rl_ro(p);
		}
	}
	else
	{
		insert(id, pass, p->left);
		if (depth(p->left) - depth(p->right) > 1)
		{
			if (id < p->left->userId)            //左左，右旋
				p = r_ro(p);
			if (id > p->left->userId)            //左右，左右旋
				p = lr_ro(p);
		}
	}
}
int userTree::depth(node* a)//递归求深度
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
		cout << "删除失败：该用户未注册!" << endl;
		return;
	}
	Delete(name, root);
}
void userTree::Delete(string name, node*& a)
{
	if (a == NULL)
		return;
	else if (name > a->userId)  //调平
	{
		Delete(name, a->right);
		if (depth(a->left) - depth(a->right) > 1)
		{
			if (a->left->right && a->left->left)   //删除过程中的特殊情况，详见PPT
				a = r_ro(a);
			else if (a->left->right)            //左右，双旋
				a = lr_ro(a);
			else                                //左左，右旋
				a = r_ro(a);
		}
	}
	else if (name < a->userId)   //调平
	{
		Delete(name, a->left);
		if (depth(a->right) - depth(a->left) > 1)
		{
			if (a->right->right && a->right->left)   //删除过程中的特殊情况，详见PPT
				a = l_ro(a);
			else if (a->right->left)            //右左，双旋
				a = rl_ro(a);
			else                                //右右，左旋
				a = l_ro(a);
		}
	}
	else     //删除
	{
		if (a->left && a->right)   //有两个孩子
		{
			a->userId = FindMin(a->right)->userId;
			a->userPassword = FindMin(a->right)->userPassword;
			Delete(name, a->right);
		}
		else                       //只有一个孩子或者没有孩子
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
node* userTree::FindMin(node* a)//删除中查找直接后继
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
void outtxt(node* a, ostream& output)  //输出数据
{
	if (a == 0)
		return;
	output << a->userId << " " << a->userPassword << endl;
	outtxt(a->left, output);
	outtxt(a->right, output);
}
ostream& operator <<(ostream& stream, userTree a)  //输出文件，将用户保存到txt中 
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