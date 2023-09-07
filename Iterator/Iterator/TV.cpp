#include "TV.h"
#include"Menu.h"
#include"SmartPoint.h"
using namespace std;

SmartPoint<Menu>menu(new Menu);

void TV::Play()
{
	initgraph(1080, 960);

	Container<IMAGE> imageList;
	IMAGE image1[3];

	loadimage(&image1[0], "1.jpg", 1080, 960);
	loadimage(&image1[1], "2.jpg", 1080, 960);
	loadimage(&image1[2], "3.jpg", 1080, 960);

	imageList.Add(image1[0]);
	imageList.Add(image1[1]);
	imageList.Add(image1[2]);

	for (IMAGE img : imageList)
	{
		putimage(0, 0, &img);
		_getch();
		cleardevice();
	}

	closegraph();

	menu->TypeMenu();

}

void TV::TVMenu()
{

}
