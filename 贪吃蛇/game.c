#include"snack.h"
void game()
{
	//初始化背景
	InitGame();
	//生成蛇
	snack* player = new_snack();
	//蛇移动&&吃食物&&结束
	
	int ret=play(player);
	//
	system("cls");
	SetPos(35, 27);
	switch (ret)
	{
	case BumpBody:
		printf("您撞到了墙，游戏失败");
		break;
	case BumpYourself:
		printf("您撞到了自己，游戏失败");
		break;
	case ExitForKey:
		printf("您已通过按键退出游戏");
		break;
	case Victory:
		printf("你已达到%d分，游戏胜利！",SCORE_VICTORY);
		break;

	default:
		printf("很抱歉游戏崩溃，请联系开发者解决BUG");
	}
	Sleep(TIME);
	return;
}
void InitGame()
{
	SetPos(80, 10);
	printf("按上下左右控制移动");
	SetPos(78, 11);
	printf("按空格加速，按alt减速"); 
	//竖着5到25横着20到达70
	SetPos(55, 3);
	printf("胜利成绩： %d", SCORE_VICTORY);
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
	SetPos(SCORE_X, SCORE_Y); printf("分数: %d",0);
}
snack* new_snack()
{
	snack* player = InitList();

	return player;
}