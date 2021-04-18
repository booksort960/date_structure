#include "doubly_Linkedlist.h"
void initlinkedlist(doulink* head)//初始化双向链表
{
	(*head).next = head;
	(*head).prev = head;
}
void LinkedlistFrontPush(doulink* head, lint n)//头插法
{
	doulink* newnode = (doulink*)malloc(sizeof(doulink));
	newnode->num = n;
	doulink*phead=(*head).next;//原头节点 
	newnode->next = phead;//新的后驱指针接入下一个
	(*head).next = newnode;//将哨兵链接新结点
	newnode->prev = head;//新结点的前驱指针指向哨兵
	phead->prev = newnode;//原头结点的前驱指针指向新的头节点
}
void LinkedlistBackpush(doulink* head, lint n)//尾插法
{
	doulink* newnode = (doulink*)malloc(sizeof(doulink));
	newnode->num = n;
	doulink* plast = (*head).prev;//找到尾结点
	newnode->prev = plast;//新的尾接入原尾结点
	newnode->next = plast->next;//新接入哨兵
	plast->next = newnode;//原尾结点next指向新的尾
	(*head).prev = newnode;//头节点的prev指向新的尾结点，形成闭环
}
void LinkedlistFrontPop(doulink* head)//头删
{
	doulink* phead = (*head).next;
	doulink* second = phead->next;
	if (phead == head)
	{
		printf("Empty List\n");
		return;
	}
	second->prev = phead->prev;
	(*head).next = second;
}
void LinkedlistBackPop(doulink* head)//尾删
{
	
	doulink* last = (*head).prev;//找到要删除的尾结点
	doulink* llast = last->prev;//找到删除后的新的尾结点
	if (last == head)
	{
		printf("Empty List\n");
		return;
	}
	(*head).prev = llast;//改变哨兵结点prev指向
	llast->next = last->next;//让新的尾结点的next接入哨兵
	free(last);
}
void LinkedlistPrint(doulink* head)//打印链表
{
	doulink* cur = (*head).next;
	while (cur != head)
	{
		printf("%d ", cur->num);
		cur = cur->next;
	}
}
