#include"snack.h"
void SetPos(short x, short y)
{
	//坐标
	COORD pos = { x,y };
	//准备修改屏幕属性
	HANDLE p = GetStdHandle(STD_OUTPUT_HANDLE);
	//实现设置输出开始位置的坐标
	SetConsoleCursorPosition(p, pos);
}
void HideCursor() {
	HANDLE hOutput = NULL;
	//获取标准输出的句柄(⽤来标识不同设备的数值)
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);//获取控制台光标
	CursorInfo.bVisible = 0;
	SetConsoleCursorInfo(hOutput, &CursorInfo);
}
void begin()
{
	srand(time(NULL));
	HideCursor();
	system("title = 贪吃蛇");
	system("mode con:cols=100 lines=30");
	setlocale(LC_ALL, "");
	inteface1();
	inteface2();
}
void inteface1()
{
	SetPos(35, 8);
	printf("欢迎来到贪吃蛇！！！");
	SetPos(35, 25);
	system("pause");
	system("cls");
}
void inteface2()
{
	SetPos(35, 8);
	printf("按上下左右控制蛇的移动");
	SetPos(35, 9);
	printf("按空格加速，按alt键减速");
	SetPos(33, 25);
	system("pause");
	system("cls");
}