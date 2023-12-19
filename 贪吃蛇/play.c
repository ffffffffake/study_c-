#include"snack.h"
//检测实物坐标是否与蛇的身体重复
bool foodcheck(Food*food,body* begin)
{
	while (begin != NULL)
	{
		if (food->x == begin->x && food->y == begin->y)
			return true;//坐标与蛇身体重了，坐标不合法。
		begin = begin->next;
	}
	//坐标合法
	return false;
}
int play(snack* player)
{
	int exit = 0;
	while (1) {
		Food* food = InitFood();
		while (food->tmp)
		{
			while (foodcheck(food,player->head->next))
			{
				free(food);
				food = InitFood();
			}
			print(player,BODY);
			Sleep(player->time);
			print(player, '\0');
			
			//0为正常执行，否者代表遇到错误，需要退出
			exit=move(food,player);
			if (exit != 0)
			{
				ListEmpty(player);
				food = NULL;
				return exit;
			}
		}
		free(food);
	}
}
Food* InitFood()
{
	short x = (rand() % 25) * 2 + 20;
	short y = (rand() % 20) + 5;
	Food* food = malloc(sizeof(Food));
	food->x = x;
	food->y = y;
	food->tmp = true;

	SetPos(x, y);
	wprintf(L"%lc", WALL);
	return food;
}
void print(snack* player, wchar_t p)
{
	body* tmp = player->head->next;
	while (tmp)
	{
		SetPos(tmp->x, tmp->y);
		if (p == '\0')
			printf("  \n");
		else
			wprintf(L"%lc\n", p);
		tmp = tmp->next;
	}
}