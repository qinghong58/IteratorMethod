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

//使用自己的智能指针
SmartPoint<TV>tv(new TV);
SmartPoint<Music>music(new Music);

void Instruction()
{
	cout << "1.动画频道" << endl;
	cout << "动画频道频道按空格进行图片的切换" << endl;
	cout << "2.音乐频道" << endl;
	cout << "支持播放音乐，暂停音乐，上一曲，下一曲" << endl;
}

void Menu::TypeMenu()
{
	system("cls");
	cout << "1.动画频道" << endl;
	cout << "2.音乐频道" << endl;
	cout << "3.频道说明" << endl;

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
