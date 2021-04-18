#include "linkedlist.h"
void initLinkedlist(list** head,list** last)//��ʼ������
{
	*head = (list*)malloc(sizeof(list));
	*(head)->n = 0;
	(*head)->next = NULL;
	*last=*head;//�ձ�״̬
}
void pushlast(list** last, int num)//β�巨
{
	list* new = (list*)malloc(sizeof(list));
	new->n = num;
	new->next = (*last)->next;
	(*last)->next = new;
	(*last) = new;
}
void pushfront(list** head, int num)//ͷ�巨
{
	list* new = (list*)malloc(sizeof(list));
	new->n = num;
	new->next = (*head)->next;
	(*head)->next = new;
}
void printlist(list** head)//��ӡ
{
	list* p = (*head)->next;
	while (p)
	{
		printf("%d ", p->n);
		p = p->next;
	}
}
void popchoice(list** head, int pos)//����λ��ɾ��
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
