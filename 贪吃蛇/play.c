#include"snack.h"
//���ʵ�������Ƿ����ߵ������ظ�
bool foodcheck(Food*food,body* begin)
{
	while (begin != NULL)
	{
		if (food->x == begin->x && food->y == begin->y)
			return true;//���������������ˣ����겻�Ϸ���
		begin = begin->next;
	}
	//����Ϸ�
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
			
			//0Ϊ����ִ�У����ߴ�������������Ҫ�˳�
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