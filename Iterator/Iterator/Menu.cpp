#include<iostream>
#include<unordered_map>
#include<functional>
#include "Menu.h"
#include"Iterator.h"
#include"Container.h"
#include"TV.h"
#include"Music.h"

using namespace std;

int TVMenu = 0;

//ʹ���Լ�������ָ��
SmartPoint<TV>tv(new TV);
SmartPoint<Music>music(new Music);

void Instruction()
{
	cout << "1.����Ƶ��" << endl;
	cout << "����Ƶ��Ƶ�����ո����ͼƬ���л�" << endl;
	cout << "2.����Ƶ��" << endl;
	cout << "֧�ֲ������֣���ͣ���֣���һ������һ��" << endl;
}

void Menu::TypeMenu()
{
	system("cls");
	cout << "1.����Ƶ��" << endl;
	cout << "2.����Ƶ��" << endl;
	cout << "3.Ƶ��˵��" << endl;

	cin >> TVMenu;

	if (TVMenu==1)
	{
		tv->Play();
	}
	else if(TVMenu==2)
	{
		music->MusicItem();
	}
	else if (TVMenu == 3)
	{
		Instruction();
		Sleep(3000);
		TypeMenu();
	}

}
