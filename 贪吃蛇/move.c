#include"snack.h"
//没有实现的功能： 1移动   2吃食物    3积分  4变速  5退出
void swap(int*x,int*y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
int move(Food* food, snack* player)
{
	if (GET_KEY(VK_F1))  return ExitForKey;  //如果读到了f1代表玩家通过按键退出
	read_key( player); //获取按键

	changeset(player);//改变坐标

	return check(food,player);  //检测是否退出
}

void read_key(snack* player)
{
	//坐标
	if (GET_KEY(VK_LEFT) && player->direction!=right) player->direction = left;
	else if (GET_KEY(VK_RIGHT) && player->direction != left) player->direction = right;
	else if (GET_KEY(VK_UP) && player->direction != down) player->direction = on;
	else if (GET_KEY(VK_DOWN) && player->direction != on) player->direction = down;
	//速度
	if (GET_KEY(VK_SPACE) && player->time < TIMEMAX)  player->time -= TIMECHANGE;
	if (GET_KEY(VK_MENU) && player->time > TIMEMIN)  player->time += TIMECHANGE;
	SetPos(20, 3);
	printf("当前时间间隔：%d", player->time);
}

void changeset(snack* player)
{
	body_change(player);
	if (player->direction == on)
		player->head->next->y--;
	if (player->direction == down)
		player->head->next->y++; 
	if (player->direction == left)
		player->head->next->x-=2;
	if (player->direction == right)
		player->head->next->x+=2;
	
}
void body_change(snack* player)
{
	body* begin = player->head->next;
	int x = begin->x; int y = begin->y;
	while (begin->next !=NULL)
	{
		begin = begin->next;
		swap(&x, &(begin->x));
		swap(&y, &(begin->y));
	}

}

int check(Food*food, snack*player)
{
	body* begin=player->head->next;
	int x = begin->x;
	int y = begin->y;
	//吃
	if (food->x == x && food->y == y)
	{
		food->tmp = false;
		player->score += player->eat_score;//加分
		if (player->score >= SCORE_VICTORY)
			return Victory;
		//打印分数
		SetPos(46, 3);
		printf("%d", player->score);



		ListPush(player, player->end->x, player->end->y);
	 }
	//碰到身体
	begin = begin->next;
	while (begin != NULL)
	{
		if (x == begin->x && y == begin->y)
			return BumpYourself;
		begin = begin->next;
	}
	//碰到墙
	if (x<WALL_LEFT || x>WALL_RIGHT || y>WALL_DOWN || y<WALL_ON)
		return BumpBody;

	//正常结束
	return normal;
}