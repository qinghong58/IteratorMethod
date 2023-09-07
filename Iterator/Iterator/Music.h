#pragma once
#include<iostream>
#include"Container.h"
#include"Iterator.h"
#include"SmartPoint.h"
#include"Config.h"
#include<graphics.h>
#include<conio.h>
#include <mmsystem.h>  
#include"Menu.h"
#pragma comment(lib, "winmm.lib")   
class Music
{
public:
	//music music_;
	
	//上一曲
	void PreMusic();

	//下一曲
	void NextMusic();

	//暂停
	void StopMusic();

	//播放
	void PlayMusic();

	void MusicItem();

};

