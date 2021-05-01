#include "queue_chain.h"
void InitQueue(QUqueue* qu)//ջ�ĳ�ʼ��
{
	qu->Dequeue = qu->Enqueue = NULL;
}
void QueuePush(QUqueue* qu, QUData n)//Ԫ�����
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
QUData QueuePop(QUqueue* qu)//Ԫ�س���
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
int QueueEmpty(QUqueue* qu)//�ж϶����Ƿ�Ϊ��
{
	if (qu->Dequeue == qu->Enqueue)
		return 1;
	return 0;
}
void QueueDestory(QUqueue* qu)//���ٶӣ���ֹ�ڴ�й©
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
void QueuePrint(QUqueue* qu)//��ӡ�����е�Ԫ�أ���ǰ����Ҫ���Ӳ��ܵõ�Ԫ��
{
	queue* cur = qu->Dequeue;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}