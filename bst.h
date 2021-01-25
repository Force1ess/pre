#ifndef force
#define force
#include<iostream>
#include<queue>
#include <stack>
#include <map>
using namespace std;
template<typename T>
class BinNode
{
public:
	T item;
	BinNode* left = 0;
	BinNode* right = 0;
	BinNode() :item(0), left(0), right(0) {}
	BinNode(T t) :item(t), left(0), right(0) {}
	
};
template<typename T>
class BST
{
public:
	BST() :myRoot(0) {}
	bool empty()const;
	void insert(T t);
	vector<T> pr() {
		vector<T> v;
		v.push_back(0);
		stack<pair<bool, BinNode<T>*>> Sta;
		Sta.push(make_pair(false, myRoot));
		while (!Sta.empty()) {
			pair<bool, BinNode<T>*> Node = Sta.top();
			Sta.pop();
			if (Node.second != nullptr) {
				if (!Node.first) {
					Sta.push(make_pair(false, Node.second->left));
					Sta.push(make_pair(true, Node.second));
					Sta.push(make_pair(false, Node.second->right));
				}
				else {
					v.push_back(Node.second->item);
				}
			}
		}
		return v;
	}
private:
	void order(BinNode<T>*);
	BinNode<T>* myRoot = new BinNode<T>();
};
template<typename T>
bool BST<T>::empty() const
{
	return myRoot == 0;
}
template<typename T>
void BST<T>::insert(T t)
{
	BinNode<T>* loc = myRoot, * parent = 0;
	bool found = false;
	while (!found && loc != 0)
	{
		parent = loc;
		if (t <= loc->item)
			loc = loc->left;
		else if (loc->item < t)
			loc = loc->right;
		else
			found = true;
	}
	if (!found)
	{
		loc = new BinNode<T>(t);
		if (parent == 0)
			myRoot = loc;
		else if (parent->item > t)
			parent->left = loc;
		else
			parent->right = loc;

	}
	else
		cout << "item is already in the tree" << endl;
}
//类模板方法和定义要写在一起
#endif force