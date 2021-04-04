#include "stack_chain.h"
void initstack(sta* a)//初始化栈
{
	top= NULL;
}
void pushstack(sta* a, int num)//入栈
{
	sta* p = (sta*)malloc(sizeof(sta));
	p->n = num;//新节点赋值
	p->point = top;
	top = p;
}
int popstack(sta* a)//出栈
{
	emptystack(a);//检查是否空栈的情况

	int date;
	sta* des = top;
	top = top->point;
	date = des->n;
	free(des);
	des = NULL;
	return date;
}
void emptystack(sta* a)//检查是否空栈的情况
{
	if (top == NULL || top->point == NULL)
	{
		printf("Stack empty");
		exit(0);
	}
}

