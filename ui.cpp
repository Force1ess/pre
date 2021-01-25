#include "ui.h"
#include<iostream>
#include<fstream>
#include"userTree.h"
#include<string>
#include<conio.h>
using namespace std;
ui::ui()
{
	ifstream Fang("userData.txt");
	string tempname;
	string temppassword;
	for (int i = 0; i < 20; i++)
	{
		getline(Fang, tempname, ' ');//一行一个数据，用户名和密码之间用空格分开，遇到空格停止
		getline(Fang, temppassword);//遇到换行停止
		Tree.insert(tempname, temppassword);
	}
}
void ui::mainset()  //主菜单
{
	system("cls");              //清空屏幕
	cout << endl << endl << endl << endl;
	cout << "                                      用户登录系统" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |        请输入指令：                                |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                 1.登录                             |" << endl;
	cout << "                   |                 2.注册新用户                       |" << endl;
	cout << "                   |                 3.退出系统并输出用户数据           |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   输入1-3: ";
	string a;
	cin >> a;
	while (a.length() != 1 || a > "3" || a < "1")
	{
	   	cout << "               	   输入错误！请重新输入1-3: ";
		cin >> a;
	}
	int t = a[0] - '0';
	switch (t)
	{
	case 1:
		login();
		break;
	case 2:
		regist(); 
		break;
	case 3:
		close(); 
		break;
	}
}
bool ui::rightPassword(string a, string b)
{
	if (a!=b)         //密码错误
		return false;
	else
		return true;
}
void ui::showUi()  //查看所有用户界面 
{
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                      所有用户数据" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	Tree.show();
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   请输入指令：" << endl;
	cout << "                   1.返回主菜单" << endl;
	cout << "                   2.退出系统并输出用户数据" << endl;
	cout << "                   输入1-2: ";
	string a;
	cin >> a;
	while (a.length() != 1 || a > "2" || a < "1")
	{
		cout << "                   指令错误！请根据提示重新输入 :";
		cin >> a;
	}
	int t = a[0] - '0';
	switch (t)
	{
	case 1:
		mainset();
		break;
	case 2:
		close();
		break;
	}
}
void ui::login()   //登录界面
{
	system("cls");
	string name;
	cout << endl << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                  用户登录界面                       |" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                          请输入用户名: ";
	cin >> name;
	cout << "                          请输入用户密码: ";
	string password;
	int i = 0;
	char ch;
	while ((ch = _getch()) != 13)//13是回车
	{
		password += ch;
		cout << "*";
	}
	cout << endl;
	node* ptr = Tree.search(name);
	if (ptr == 0)
	{
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   |      登录错误：用户名不存在                            |" << endl;
		cout << "                   |                                                     |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   1.重新登录" << endl;
		cout << "                   2.返回主菜单" << endl;
		cout << "                   3.退出系统并输出用户数据" << endl;
		cout << "                   输入1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			login();
			break;
		case 2:
			mainset();
			break;
		case 3:
			close();
			break;
		}
	}
	else if (rightPassword(password, ptr->userPassword) && name == "郑昊")//进入管理员界面，管理员账户不可修改密码
	{
		cout << "                   ------------------------------------------------------" << endl;

		cout << "                   |      登录成功！                                    |" << endl;
		cout << "                   |      尊敬的管理员用户，您好！                          |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   请输入指令：" << endl;
		cout << "                   1.查看所有用户数据" << endl;
		cout << "                   2.删除指定用户" << endl;
		cout << "                   3.返回主菜单" << endl;
		cout << "                   4.退出系统并输出用户数据" << endl;
		cout << "                   输入1-4: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "4" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-4: ";
			cin >> a;
		}
		int t = a[0] - '0';
		string delname;
		string b;
		switch (t)
		{
		case 1:
			showUi();
			break;
		case 2:
			cout << "                   输入想删除的用户账号: ";
			cin >> delname;
			Deleteuser(delname);
			break;
		case 3:
			mainset();
			break;
		case 4:
			close();
			break;
		}
	}
	else if (rightPassword(password, ptr->userPassword))
	{
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   |      登录成功！                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   请输入指令：" << endl;
		cout << "                   1.修改密码" << endl;
		cout << "                   2.删除用户" << endl;
		cout << "                   3.返回主菜单" << endl;
		cout << "                   4.退出系统并输出用户数据" << endl;
		cout << "                   输入1-4: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "4" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-4: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			passChange(Tree.search(name)); 
			break;
		case 2:
			Delete(Tree.search(name));
			break;
		case 3:
			mainset(); 
			break;
		case 4:
			close(); 
			break;
		}
	}
	else
	{
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   |      登录失败：密码错误                               |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   请输入指令：" << endl;
		cout << "                   1.重新登录" << endl;
		cout << "                   2.返回主菜单" << endl;
		cout << "                   3.退出系统并输出用户数据" << endl;
		cout << "                   输入1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			login();
			break;
		case 2:
			mainset();
			break;
		case 3:
			close();
			break;
		}
	}
}
bool ui::passCheck(string pass)
//密码检验
{
	
	if (pass.length() <= 4||pass.length()>12)
		return true;
	if (pass == "123456")
		return true;
	if (pass == "12345678")
		return true;
	if (pass == "123456789")
		return true;
	if (pass == "8888")
		return true;
	if (pass == "888888")
		return true;
	if (pass == "88888888")
		return true;
	bool flag = false;
	for(char c:pass)
	{
		if (c != pass[0]) { flag = true;break; }
	}
	return flag;
}
void ui::regist()  //注册 
{
	string id, pass1, pass2;
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                      新用户注册界面" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                        请输入想要注册的用户名:";
	cin >> id;
	cout << "                        请输入密码:";
	char ch1;
	while ((ch1 = _getch()) != 13)//13是回车
	{
		pass1 += ch1;
		cout << "*";
	}
	cout << endl;
	cout << "                        请确认密码:";
	char ch2;
	while ((ch2 = _getch()) != 13)//13是回车
	{
		pass2 += ch2;
		cout << "*";
	}
	cout << endl;
	node* ptr = Tree.search(id);
	if (ptr == 0 && pass1 == pass2 && !passCheck(pass1))
	{
		Tree.insert(id, pass1);
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   |     注册成功！                                       |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   请输入指令：" << endl;
		cout << "                   1.返回主菜单" << endl;
		cout << "                   2.退出系统并输出用户数据" << endl;
		cout << "                   输入1-2: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-2: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			mainset();
			break;
		case 2:
			close();
			break;
		}
	}
	else if (ptr != 0) 
	{
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   |     注册失败：用户名已存在                             |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   请输入指令：" << endl;
		cout << "                   1.重新注册" << endl;
		cout << "                   2.返回主菜单" << endl;
		cout << "                   3.退出系统并输出用户数据" << endl;
		cout << "                   输入1-3:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			regist();
			break;
		case 2:
			mainset();
			break;
		case 3:
			close();
			break;
		}
	}
	else if (pass1 != pass2) 
	{
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   |     注册失败：两次密码不一致                       |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   请输入指令：" << endl;
		cout << "                   1.重新注册" << endl;
		cout << "                   2.返回主菜单" << endl;
		cout << "                   3.退出系统并输出用户数据" << endl;
		cout << "                   输入1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			regist();
			break;
		case 2:
			mainset();
			break;
		case 3:
			close();
			break;
		}
	}
	else if (passCheck(pass1))
	{
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   |     注册失败：密码过于简单                         |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   请输入指令：" << endl;
		cout << "                   1.重新注册" << endl;
		cout << "                   2.返回主菜单" << endl;
		cout << "                   3.退出系统并输出用户数据" << endl;
		cout << "                   输入1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			regist();
			break;
		case 2:
			mainset();
			break;
		case 3:
			close();
			break;
		}
	}
}
void ui::passChange(node* ptr)                   //修改密码 
{
	string name = ptr->userId;
	string password;
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                   用户密码修改界面                  |" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                         请输入新密码:";

	char ch;
	while ((ch = _getch()) != 13)//13是回车
	{
		password += ch;
		cout << "*";
	}
	if (!passCheck(password) && password != ptr->userPassword)
	{
		ptr->userPassword = password;
		cout << "                   |      修改密码成功！                                  |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   请输入指令：" << endl;
		cout << "                   1.返回主菜单" << endl;
		cout << "                   2.退出系统并输出用户数据" << endl;
		cout << "                   输入1-2:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-2: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			mainset();
			break;
		case 2:
			close();
			break;
		}
	}
	else if (passCheck(password))
	{
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   |      密码修改失败：密码过于简单                        |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   请输入指令：" << endl;
		cout << "                   1.重新修改密码" << endl;
		cout << "                   1.返回主菜单" << endl;
		cout << "                   2.退出系统并输出用户数据" << endl;
		cout << "                   输入1-3:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			passChange(Tree.search(name));
			break;
		case 2:
			mainset();
			break;
		case 3:
			close();
			break;
		}
	}
	else if (password == ptr->userPassword)
	{
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   |      修改密码失败：新密码不能与原密码相同                |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   请输入指令：" << endl;
		cout << "                   1.重新修改密码" << endl;
		cout << "                   1.返回主菜单" << endl;
		cout << "                   2.退出系统并输出用户数据" << endl;
		cout << "                   输入1-3:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			passChange(Tree.search(name));
			break;
		case 2:
			mainset();
			break;
		case 3:
			close();
			break;
		}
	}
}
void ui::Deleteuser(string a)  //删除指定用户 
{
	node* ptr = Tree.search(a);
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                  删除用户界面                        |" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   ------------------------------------------------------" << endl;

	if (ptr == 0)
	{
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   |      删除用户失败：用户不存在                          |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   请输入指令：" << endl;
		cout << "                   1.返回主菜单" << endl;
		cout << "                   2.退出系统并输出用户数据" << endl;
		cout << "                   输入1-2: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-2: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			mainset();
			break;
		case 2:
			close();
			break;
		}
	}
	else
	{
		Tree.Delete(ptr->userId);
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   |      删除该用户成功！                                 |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   请输入指令：" << endl;
		cout << "                   1.返回主菜单" << endl;
		cout << "                   2.退出系统并输出用户数据" << endl;
		cout << "                   输入1-2: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-2: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			mainset();
			break;
		case 2:
			close();
			break;
		}
	}
}
void ui::Delete(node* p)  //删除用户 
{
	Tree.Delete(p->userId);
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                  删除用户界面                        |" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |      删除该用户成功！                                 |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   请输入指令：" << endl;
	cout << "                   1.返回主菜单" << endl;
	cout << "                   2.退出系统并输出用户数据" << endl;
	cout << "                   输入1-2: ";
	string a;
	cin >> a;
	while (a.length() != 1 || a > "2" || a < "1")
	{
		cout << "                   输入错误！请重新输入1-2: ";
		cin >> a;
	}
	int t = a[0] - '0';
	switch (t)
	{
	case 1:
		mainset();
		break;
	case 2:
		close();
		break;
	}
}
void ui::close()  //将用户保存到txt中
{
	ofstream FFang("userData.txt");
	FFang << Tree;
	FFang.close();
}