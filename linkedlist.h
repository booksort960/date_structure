#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct link
{
	int n;
	struct link* next;
}list;
void initLinkedlist(list** a, list** b);//��ʼ������
void pushlast(list**last, int num);//β�巨
void pushfront(list**head, int num);//ͷ�巨
void printlist(list**head);//��ӡ
void popchoice(list**head, int pos);//����λ��ɾ��




