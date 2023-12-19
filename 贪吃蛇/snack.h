#define _CRT_SECURE_NO_WARNINGS 1
#define WALL L'■'
#define BODY L'●'
#define TIME 500
#define TIMECHANGE 100
#define TIMEMIN 50
#define TIMEMAX 2000

#define SCORE_X 40
#define SCORE_Y 3
#define SCORE_VICTORY 1000
#define SCORE_EAT 100
#define WALL_ON  5
#define WALL_DOWN  25
#define WALL_LEFT 20
#define WALL_RIGHT 70
#define SNACKBEGINX 50
#define SNACKBEGINY 20


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<Windows.h>
#include<time.h>
#include<locale.h>
#include<stdbool.h>

#define GET_KEY(vk)   (GetAsyncKeyState(vk)&0x1)

typedef struct body {
	int x;
	int y;
	struct body* next;
}body;//存放单个蛇的节点
typedef struct
{
	int direction;//方向
	int score; //得分
	int time;	//间隔时间
	int eat_score;   //每吃一个的得分
	body* head;
	body* end;
}snack;//存放整条蛇
typedef struct Food{
	int x;
	int y;
	bool tmp;
}Food;
//方向
enum dir {
	on=1,
	down,
	left,
	right
};
//退出时的结果
enum exit
{
	normal,
	BumpBody,
	BumpYourself,
	ExitForKey,
	Victory,
	ProgramCrashes
};
//打印开始界面和规则界面
void begin();
//设置坐标
void SetPos(short x, short y);
//隐藏光标
void HideCursor();
//开始界面
void inteface1();
//规则界面
void inteface2();
//游戏开始
void game();
//生成背景
void InitGame();
//新建蛇
 snack* new_snack();

//蛇的初始化
snack* InitList();
//尾增加
void ListPush(snack* player,short x, short y);
//销毁
void ListEmpty(snack* player);
//游戏开始
int play(snack* player);
//生成食物
Food* InitFood();
//打印蛇身
void print(snack* player,wchar_t p);
//移动
int move(Food*, snack*);
//获取按键
void read_key(snack*);
//检测是否退出
int check(Food*, snack*);
//改变坐标
void changeset(snack*);
//改变身体坐标
void body_change(snack* player);
//交换
void swap(int* x, int* y);
//食物坐标检测
bool foodcheck(Food*);
