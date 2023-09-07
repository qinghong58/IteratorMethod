#include "Music.h"


Container<string> music_item;
SmartPoint<Menu>menu_(new Menu);

string ma[3] = { "Mario.mp3" ,"Paino.mp3","jinitaimei.mp3" };

int musicflag = 0;

void Music::PreMusic()
{
	for (int i = 0; i <= 1; i++)
	{
		mciSendString(("close " + ma[i]).c_str(), NULL, 0, NULL);    // ��ͣ����
		mciSendString(("Play " + ma[i + 1] + " repeat").c_str(), nullptr, 0, nullptr);
	}

}

void Music::NextMusic()
{
	for (int i = 2; i >= 2; i--)
	{
		mciSendString(("close " + ma[i]).c_str(), NULL, 0, NULL);    // ��ͣ����
		mciSendString(("Play " + ma[i - 1] + " repeat").c_str(), nullptr, 0, nullptr);

	}

}

void Music::StopMusic()
{
	mciSendString(("close " + ma[0]).c_str(), NULL, 0, NULL);    // ��ͣ����
}

void Music::PlayMusic()
{


	music_item.Add(ma[0]);
	music_item.Add(ma[1]);
	music_item.Add(ma[2]);


	
	mciSendString(("Play " + ma[0] + " repeat").c_str(), nullptr, 0, nullptr);
	//_getch();
	
}

void Music::MusicItem()
{
	cout << "����Ƶ��" << endl;
	cout << "1.��ʼ����" << endl;
	cout << "2.��ͣ����" << endl;
	cout << "3.��һ��" << endl;
	cout << "4.��һ��" << endl;
	cout << "5.�˳�Ƶ��" << endl;

	while (cin >> musicflag)
	{
		switch (musicflag)
		{
		case 1://��������
			cout << "���ڲ�������" << endl;
			PlayMusic();
			break;
		case 2://ֹͣ����
			cout << "���ֲ�����ֹͣ" << endl;
			StopMusic();
			break;
		case 3:
			cout << "������һ��" << endl;
			PreMusic();
			break;
		case 4:
			cout << "������һ��" << endl;
			NextMusic();
			break;
		case 5:
			cout << "�˳�Ƶ��" << endl;
			menu_->TypeMenu();
			break;
		}

	}

}

