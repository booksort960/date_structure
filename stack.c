#include "stack.h"
void initstack(sta* a)//初始化栈
{
	a->capacity = N;
	a->base = (stae*)malloc(sizeof(stae) * (a->capacity));
	a->top = a->base;
}
void emptystack(sta* a)//检查是否空栈的情况
{
	if (a->top == a->base)
	{
		printf("Stack Empty\n");
		exit(0);
	}
}
void fullstack(sta* a)//检查栈的情况
{
	
	if (a->top-a->base==a->capacity)
	{
		int i = a->capacity;
		printf("Stack Full,expand sucess\n");
		a->capacity = N * 2;
		a->base = (stae*)realloc(a->base,sizeof(stae) * (a->capacity));
		a->top = a->base + i;
	}
}
void pushstack(sta* a, int num)//入栈
{
	fullstack(a);//检查是否满栈的情况
	a->top->n = num;
	(a->top)++;
}
void printstack(sta* a)//打印栈
{
	for (int i = 0; i < a->top-a->base; i++)
	{
		printf("%d ", (a->base+i)->n);
	}
}
void popstack(sta* a)//出栈
{
	emptystack(a);//检查栈是否空栈的情况
	a->top--;
}
