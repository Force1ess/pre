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
		getline(Fang, tempname, ' ');//һ��һ�����ݣ��û���������֮���ÿո�ֿ��������ո�ֹͣ
		getline(Fang, temppassword);//��������ֹͣ
		Tree.insert(tempname, temppassword);
	}
}
void ui::mainset()  //���˵�
{
	system("cls");              //�����Ļ
	cout << endl << endl << endl << endl;
	cout << "                                      �û���¼ϵͳ" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |        ������ָ�                                |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                 1.��¼                             |" << endl;
	cout << "                   |                 2.ע�����û�                       |" << endl;
	cout << "                   |                 3.�˳�ϵͳ������û�����           |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   ����1-3: ";
	string a;
	cin >> a;
	while (a.length() != 1 || a > "3" || a < "1")
	{
	   	cout << "               	   �����������������1-3: ";
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
	if (a!=b)         //�������
		return false;
	else
		return true;
}
void ui::showUi()  //�鿴�����û����� 
{
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                      �����û�����" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	Tree.show();
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   ������ָ�" << endl;
	cout << "                   1.�������˵�" << endl;
	cout << "                   2.�˳�ϵͳ������û�����" << endl;
	cout << "                   ����1-2: ";
	string a;
	cin >> a;
	while (a.length() != 1 || a > "2" || a < "1")
	{
		cout << "                   ָ������������ʾ�������� :";
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
void ui::login()   //��¼����
{
	system("cls");
	string name;
	cout << endl << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                  �û���¼����                       |" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                          �������û���: ";
	cin >> name;
	cout << "                          �������û�����: ";
	string password;
	int i = 0;
	char ch;
	while ((ch = _getch()) != 13)//13�ǻس�
	{
		password += ch;
		cout << "*";
	}
	cout << endl;
	node* ptr = Tree.search(name);
	if (ptr == 0)
	{
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   |      ��¼�����û���������                            |" << endl;
		cout << "                   |                                                     |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   1.���µ�¼" << endl;
		cout << "                   2.�������˵�" << endl;
		cout << "                   3.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   �����������������1-3: ";
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
	else if (rightPassword(password, ptr->userPassword) && name == "֣�")//�������Ա���棬����Ա�˻������޸�����
	{
		cout << "                   ------------------------------------------------------" << endl;

		cout << "                   |      ��¼�ɹ���                                    |" << endl;
		cout << "                   |      �𾴵Ĺ���Ա�û������ã�                          |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   ������ָ�" << endl;
		cout << "                   1.�鿴�����û�����" << endl;
		cout << "                   2.ɾ��ָ���û�" << endl;
		cout << "                   3.�������˵�" << endl;
		cout << "                   4.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-4: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "4" || a < "1")
		{
			cout << "                   �����������������1-4: ";
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
			cout << "                   ������ɾ�����û��˺�: ";
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
		cout << "                   |      ��¼�ɹ���                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   ������ָ�" << endl;
		cout << "                   1.�޸�����" << endl;
		cout << "                   2.ɾ���û�" << endl;
		cout << "                   3.�������˵�" << endl;
		cout << "                   4.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-4: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "4" || a < "1")
		{
			cout << "                   �����������������1-4: ";
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
		cout << "                   |      ��¼ʧ�ܣ��������                               |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   ������ָ�" << endl;
		cout << "                   1.���µ�¼" << endl;
		cout << "                   2.�������˵�" << endl;
		cout << "                   3.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   �����������������1-3: ";
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
//�������
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
void ui::regist()  //ע�� 
{
	string id, pass1, pass2;
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                      ���û�ע�����" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                        ��������Ҫע����û���:";
	cin >> id;
	cout << "                        ����������:";
	char ch1;
	while ((ch1 = _getch()) != 13)//13�ǻس�
	{
		pass1 += ch1;
		cout << "*";
	}
	cout << endl;
	cout << "                        ��ȷ������:";
	char ch2;
	while ((ch2 = _getch()) != 13)//13�ǻس�
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
		cout << "                   |     ע��ɹ���                                       |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   ������ָ�" << endl;
		cout << "                   1.�������˵�" << endl;
		cout << "                   2.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-2: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   �����������������1-2: ";
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
		cout << "                   |     ע��ʧ�ܣ��û����Ѵ���                             |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   ������ָ�" << endl;
		cout << "                   1.����ע��" << endl;
		cout << "                   2.�������˵�" << endl;
		cout << "                   3.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-3:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   �����������������1-3: ";
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
		cout << "                   |     ע��ʧ�ܣ��������벻һ��                       |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   ������ָ�" << endl;
		cout << "                   1.����ע��" << endl;
		cout << "                   2.�������˵�" << endl;
		cout << "                   3.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   �����������������1-3: ";
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
		cout << "                   |     ע��ʧ�ܣ�������ڼ�                         |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   ������ָ�" << endl;
		cout << "                   1.����ע��" << endl;
		cout << "                   2.�������˵�" << endl;
		cout << "                   3.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   �����������������1-3: ";
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
void ui::passChange(node* ptr)                   //�޸����� 
{
	string name = ptr->userId;
	string password;
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                   �û������޸Ľ���                  |" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                         ������������:";

	char ch;
	while ((ch = _getch()) != 13)//13�ǻس�
	{
		password += ch;
		cout << "*";
	}
	if (!passCheck(password) && password != ptr->userPassword)
	{
		ptr->userPassword = password;
		cout << "                   |      �޸�����ɹ���                                  |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   ������ָ�" << endl;
		cout << "                   1.�������˵�" << endl;
		cout << "                   2.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-2:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   �����������������1-2: ";
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
		cout << "                   |      �����޸�ʧ�ܣ�������ڼ�                        |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   ������ָ�" << endl;
		cout << "                   1.�����޸�����" << endl;
		cout << "                   1.�������˵�" << endl;
		cout << "                   2.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-3:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   �����������������1-3: ";
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
		cout << "                   |      �޸�����ʧ�ܣ������벻����ԭ������ͬ                |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   ������ָ�" << endl;
		cout << "                   1.�����޸�����" << endl;
		cout << "                   1.�������˵�" << endl;
		cout << "                   2.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-3:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   �����������������1-3: ";
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
void ui::Deleteuser(string a)  //ɾ��ָ���û� 
{
	node* ptr = Tree.search(a);
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                  ɾ���û�����                        |" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   ------------------------------------------------------" << endl;

	if (ptr == 0)
	{
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   |      ɾ���û�ʧ�ܣ��û�������                          |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   ������ָ�" << endl;
		cout << "                   1.�������˵�" << endl;
		cout << "                   2.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-2: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   �����������������1-2: ";
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
		cout << "                   |      ɾ�����û��ɹ���                                 |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   |                                                    |" << endl;
		cout << "                   ------------------------------------------------------" << endl;
		cout << "                   ������ָ�" << endl;
		cout << "                   1.�������˵�" << endl;
		cout << "                   2.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-2: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   �����������������1-2: ";
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
void ui::Delete(node* p)  //ɾ���û� 
{
	Tree.Delete(p->userId);
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                  ɾ���û�����                        |" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |      ɾ�����û��ɹ���                                 |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   |                                                    |" << endl;
	cout << "                   ------------------------------------------------------" << endl;
	cout << "                   ������ָ�" << endl;
	cout << "                   1.�������˵�" << endl;
	cout << "                   2.�˳�ϵͳ������û�����" << endl;
	cout << "                   ����1-2: ";
	string a;
	cin >> a;
	while (a.length() != 1 || a > "2" || a < "1")
	{
		cout << "                   �����������������1-2: ";
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
void ui::close()  //���û����浽txt��
{
	ofstream FFang("userData.txt");
	FFang << Tree;
	FFang.close();
}