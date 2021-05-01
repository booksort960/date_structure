#include "queue_chain.h"
void InitQueue(QUqueue* qu)//栈的初始化
{
	qu->Dequeue = qu->Enqueue = NULL;
}
void QueuePush(QUqueue* qu, QUData n)//元素入队
{
	queue* newcell = (QUData*)malloc(sizeof(QUData));
	newcell->data = n;
	newcell->next = NULL;
	if (qu->Dequeue == NULL)
	{
		qu->Enqueue = qu->Dequeue = newcell;
	}
	else
	{
		qu->Enqueue->next = newcell;
		qu->Enqueue = newcell;
	}
}
QUData QueuePop(QUqueue* qu)//元素出队
{
	if (QueueEmpty(qu))
	{
		printf("Queue Is Empty");
		exit(-1);
	}
	QUData ret = qu->Dequeue->data;
	qu->Dequeue = qu->Dequeue->next;
	return ret;
}
int QueueEmpty(QUqueue* qu)//判断队列是否为空
{
	if (qu->Dequeue == qu->Enqueue)
		return 1;
	return 0;
}
void QueueDestory(QUqueue* qu)//销毁队，防止内存泄漏
{
	queue* cur = qu->Dequeue;
	while (cur)
	{
		queue* pnext = cur->next;
		free(cur);
		cur = pnext;
	}
	qu->Dequeue = qu->Enqueue = NULL;
}
void QueuePrint(QUqueue* qu)//打印队列中的元素，但前提是要出队才能得到元素
{
	queue* cur = qu->Dequeue;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}