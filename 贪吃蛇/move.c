#include"snack.h"
//û��ʵ�ֵĹ��ܣ� 1�ƶ�   2��ʳ��    3����  4����  5�˳�
void swap(int*x,int*y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
int move(Food* food, snack* player)
{
	if (GET_KEY(VK_F1))  return ExitForKey;  //���������f1�������ͨ�������˳�
	read_key( player); //��ȡ����

	changeset(player);//�ı�����

	return check(food,player);  //����Ƿ��˳�
}

void read_key(snack* player)
{
	//����
	if (GET_KEY(VK_LEFT) && player->direction!=right) player->direction = left;
	else if (GET_KEY(VK_RIGHT) && player->direction != left) player->direction = right;
	else if (GET_KEY(VK_UP) && player->direction != down) player->direction = on;
	else if (GET_KEY(VK_DOWN) && player->direction != on) player->direction = down;
	//�ٶ�
	if (GET_KEY(VK_SPACE) && player->time < TIMEMAX)  player->time -= TIMECHANGE;
	if (GET_KEY(VK_MENU) && player->time > TIMEMIN)  player->time += TIMECHANGE;
	SetPos(20, 3);
	printf("��ǰʱ������%d", player->time);
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
	//��
	if (food->x == x && food->y == y)
	{
		food->tmp = false;
		player->score += player->eat_score;//�ӷ�
		if (player->score >= SCORE_VICTORY)
			return Victory;
		//��ӡ����
		SetPos(46, 3);
		printf("%d", player->score);



		ListPush(player, player->end->x, player->end->y);
	 }
	//��������
	begin = begin->next;
	while (begin != NULL)
	{
		if (x == begin->x && y == begin->y)
			return BumpYourself;
		begin = begin->next;
	}
	//����ǽ
	if (x<WALL_LEFT || x>WALL_RIGHT || y>WALL_DOWN || y<WALL_ON)
		return BumpBody;

	//��������
	return normal;
}