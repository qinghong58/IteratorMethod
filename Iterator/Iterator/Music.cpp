#include "Music.h"


Container<string> music_item;
SmartPoint<Menu>menu_(new Menu);

string ma[3] = { "Mario.mp3" ,"Paino.mp3","jinitaimei.mp3" };

int musicflag = 0;

void Music::PreMusic()
{
	for (int i = 0; i <= 1; i++)
	{
		mciSendString(("close " + ma[i]).c_str(), NULL, 0, NULL);    // ‘›Õ£“Ù¿÷
		mciSendString(("Play " + ma[i + 1] + " repeat").c_str(), nullptr, 0, nullptr);
	}

}

void Music::NextMusic()
{
	for (int i = 2; i >= 2; i--)
	{
		mciSendString(("close " + ma[i]).c_str(), NULL, 0, NULL);    // ‘›Õ£“Ù¿÷
		mciSendString(("Play " + ma[i - 1] + " repeat").c_str(), nullptr, 0, nullptr);

	}

}

void Music::StopMusic()
{
	mciSendString(("close " + ma[0]).c_str(), NULL, 0, NULL);    // ‘›Õ£“Ù¿÷
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
	cout << "“Ù¿÷∆µµ¿" << endl;
	cout << "1.ø™ º≤•∑≈" << endl;
	cout << "2.‘›Õ£≤•∑≈" << endl;
	cout << "3.œ¬“ª«˙" << endl;
	cout << "4.…œ“ª«˙" << endl;
	cout << "5.ÕÀ≥ˆ∆µµ¿" << endl;

	while (cin >> musicflag)
	{
		switch (musicflag)
		{
		case 1://≤•∑≈“Ù¿÷
			cout << "’˝‘⁄≤•∑≈“Ù¿÷" << endl;
			PlayMusic();
			break;
		case 2://Õ£÷π“Ù¿÷
			cout << "“Ù¿÷≤•∑≈“—Õ£÷π" << endl;
			StopMusic();
			break;
		case 3:
			cout << "“Ù¿÷…œ“ª«˙" << endl;
			PreMusic();
			break;
		case 4:
			cout << "“Ù¿÷œ¬“ª«˙" << endl;
			NextMusic();
			break;
		case 5:
			cout << "ÕÀ≥ˆ∆µµ¿" << endl;
			menu_->TypeMenu();
			break;
		}

	}

}

