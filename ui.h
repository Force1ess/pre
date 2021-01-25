#pragma once
#include"userTree.h"
class ui
{
public:
	userTree Tree;
	ui();             
	void mainset();   //主要功能 
	void login();//登录
	void regist();      //注册 
	bool passCheck(string pass);//判断密码是否符合规范
	void passChange(node* a); //修改密码 
	void Delete(node* a); //删除用户 
	void close();       //保存用户数据到本地
	bool rightPassword(string a, string b);//检查密码是否正确
	void showUi();//查看所有用户界面 
	void Deleteuser(string a);//删除用户
};