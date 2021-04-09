#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct link
{
	int n;
	struct link* next;
}list;
void initLinkedlist(list** a, list** b);//初始化链表
void pushlast(list**last, int num);//尾插法
void pushfront(list**head, int num);//头插法
void printlist(list**head);//打印
void popchoice(list**head, int pos);//任意位置删除




