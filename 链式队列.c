#include "queue_chain.h"
void Test(void)
{
	QUqueue qu;
	InitQueue(&qu);//初始化队列
	QueuePush(&qu, 1);//元素入队
	QueuePush(&qu, 2);//元素入队
	QueuePush(&qu, 3);//元素入队
	QueuePush(&qu, 4);//元素入队
	QueuePop(&qu);//元素出队
	QueuePop(&qu);//元素出队
	QueuePush(&qu, 5);//元素入队
	QueuePush(&qu, 6);//元素入队
	QueuePrint(&qu);
}

int main(void)
{
	Test();
	QUqueue qu;
	InitQueue(&qu);//初始化队列
}