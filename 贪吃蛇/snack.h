#define _CRT_SECURE_NO_WARNINGS 1
#define WALL L'��'
#define BODY L'��'
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
}body;//��ŵ����ߵĽڵ�
typedef struct
{
	int direction;//����
	int score; //�÷�
	int time;	//���ʱ��
	int eat_score;   //ÿ��һ���ĵ÷�
	body* head;
	body* end;
}snack;//���������
typedef struct Food{
	int x;
	int y;
	bool tmp;
}Food;
//����
enum dir {
	on=1,
	down,
	left,
	right
};
//�˳�ʱ�Ľ��
enum exit
{
	normal,
	BumpBody,
	BumpYourself,
	ExitForKey,
	Victory,
	ProgramCrashes
};
//��ӡ��ʼ����͹������
void begin();
//��������
void SetPos(short x, short y);
//���ع��
void HideCursor();
//��ʼ����
void inteface1();
//�������
void inteface2();
//��Ϸ��ʼ
void game();
//���ɱ���
void InitGame();
//�½���
 snack* new_snack();

//�ߵĳ�ʼ��
snack* InitList();
//β����
void ListPush(snack* player,short x, short y);
//����
void ListEmpty(snack* player);
//��Ϸ��ʼ
int play(snack* player);
//����ʳ��
Food* InitFood();
//��ӡ����
void print(snack* player,wchar_t p);
//�ƶ�
int move(Food*, snack*);
//��ȡ����
void read_key(snack*);
//����Ƿ��˳�
int check(Food*, snack*);
//�ı�����
void changeset(snack*);
//�ı���������
void body_change(snack* player);
//����
void swap(int* x, int* y);
//ʳ��������
bool foodcheck(Food*);
