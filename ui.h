#pragma once
#include"userTree.h"
class ui
{
public:
	userTree Tree;
	ui();             
	void mainset();   //��Ҫ���� 
	void login();//��¼
	void regist();      //ע�� 
	bool passCheck(string pass);//�ж������Ƿ���Ϲ淶
	void passChange(node* a); //�޸����� 
	void Delete(node* a); //ɾ���û� 
	void close();       //�����û����ݵ�����
	bool rightPassword(string a, string b);//��������Ƿ���ȷ
	void showUi();//�鿴�����û����� 
	void Deleteuser(string a);//ɾ���û�
};