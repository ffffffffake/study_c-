#include"snack.h"
//³õÊ¼»¯
snack* InitList()
{
	body* head =(body*)malloc(sizeof(body));
	head->x =head->y= 0;
	
	body* node = (body*)malloc(sizeof(body));
	node->x = SNACKBEGINX;
	node->y = SNACKBEGINY;
	head->next =node;
	body* node2 = (body*)malloc(sizeof(body));
	node2->x =52;
	node2->y = 20;
	node->next = node2;
	node2->next = NULL;
	snack* player =(snack*) malloc(sizeof(snack));
	player->head = head;
	player->end = node2;
	player->score = player->direction = 0;
	player->direction = on;
	player->eat_score = SCORE_EAT;
	player->time = TIME;
	return player;
}
//Î²²å
void ListPush(snack* player,short x,short y)
{
	body* tmp =(body*) malloc(sizeof(body));
	tmp->x = x;
	tmp->y = y;
	tmp->next = NULL;
	player->end->next = tmp;
	player->end = tmp;
}
//Ïú»Ù
void ListEmpty(snack* player)
{
	assert(player);
	assert(player->head && player->end);

	body* tmp = player->head;
	while (tmp!= NULL)
	{
		
		player->head = player->head->next;
		free(tmp);
		tmp = player->head;
	}
	free(player);
	player = NULL;
	tmp = NULL;
}