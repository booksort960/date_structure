#include "linkedlist.h"
void initLinkedlist(list** head,list** last)//初始化链表
{
	*head = (list*)malloc(sizeof(list));
	*(head)->n = 0;
	(*head)->next = NULL;
	*last=*head;//空表状态
}
void pushlast(list** last, int num)//尾插法
{
	list* new = (list*)malloc(sizeof(list));
	new->n = num;
	new->next = (*last)->next;
	(*last)->next = new;
	(*last) = new;
}
void pushfront(list** head, int num)//头插法
{
	list* new = (list*)malloc(sizeof(list));
	new->n = num;
	new->next = (*head)->next;
	(*head)->next = new;
}
void printlist(list** head)//打印
{
	list* p = (*head)->next;
	while (p)
	{
		printf("%d ", p->n);
		p = p->next;
	}
}
void popchoice(list** head, int pos)//任意位置删除
{
	assert(pos<8&pos>=0);
	int i = 0;
	list* pre = *head;
	list* cur = (*head)->next;
	while (i < pos)
	{
		pre = cur;
		cur = cur->next;
		i++;
	}
	pre->next = cur->next;
	free(cur);

}
