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
	
	//��һ��
	void PreMusic();

	//��һ��
	void NextMusic();

	//��ͣ
	void StopMusic();

	//����
	void PlayMusic();

	void MusicItem();

};

