#include"snack.h"
void game()
{
	//��ʼ������
	InitGame();
	//������
	snack* player = new_snack();
	//���ƶ�&&��ʳ��&&����
	
	int ret=play(player);
	//
	system("cls");
	SetPos(35, 27);
	switch (ret)
	{
	case BumpBody:
		printf("��ײ����ǽ����Ϸʧ��");
		break;
	case BumpYourself:
		printf("��ײ�����Լ�����Ϸʧ��");
		break;
	case ExitForKey:
		printf("����ͨ�������˳���Ϸ");
		break;
	case Victory:
		printf("���Ѵﵽ%d�֣���Ϸʤ����",SCORE_VICTORY);
		break;

	default:
		printf("�ܱ�Ǹ��Ϸ����������ϵ�����߽��BUG");
	}
	Sleep(TIME);
	return;
}
void InitGame()
{
	SetPos(80, 10);
	printf("���������ҿ����ƶ�");
	SetPos(78, 11);
	printf("���ո���٣���alt����"); 
	//����5��25����20����70
	SetPos(55, 3);
	printf("ʤ���ɼ��� %d", SCORE_VICTORY);
	for (int i = WALL_LEFT-2; i <= WALL_RIGHT+2; i += 2)
	{
		SetPos(i, WALL_ON-1);   wprintf(L"%lc",WALL);
		SetPos(i, WALL_DOWN+1);   wprintf(L"%lc", WALL);
	}
	for (int j = WALL_ON-1; j <= WALL_DOWN+1; j++)
	{
		SetPos(WALL_LEFT-2,j);   wprintf(L"%lc", WALL);
		SetPos(WALL_RIGHT+2, j);   wprintf(L"%lc", WALL);
	}
	SetPos(SCORE_X, SCORE_Y); printf("����: %d",0);
}
snack* new_snack()
{
	snack* player = InitList();

	return player;
}