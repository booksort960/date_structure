#include "queue_chain.h"
void Test(void)
{
	QUqueue qu;
	InitQueue(&qu);//��ʼ������
	QueuePush(&qu, 1);//Ԫ�����
	QueuePush(&qu, 2);//Ԫ�����
	QueuePush(&qu, 3);//Ԫ�����
	QueuePush(&qu, 4);//Ԫ�����
	QueuePop(&qu);//Ԫ�س���
	QueuePop(&qu);//Ԫ�س���
	QueuePush(&qu, 5);//Ԫ�����
	QueuePush(&qu, 6);//Ԫ�����
	QueuePrint(&qu);
}

int main(void)
{
	Test();
	QUqueue qu;
	InitQueue(&qu);//��ʼ������
}