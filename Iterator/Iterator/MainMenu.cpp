#include<iostream>
#include"Container.h"
#include"Iterator.h"
#include"SmartPoint.h"
#include <graphics.h>   
#include<conio.h>
#include <mmsystem.h>  
#include"Config.h"
#include"TV.h"
#include"Music.h"
#include"Menu.h"
#pragma comment(lib, "winmm.lib")   
using namespace std;

Menu menu_type;
int main()
{	
	menu_type.TypeMenu();
	return 0;
}