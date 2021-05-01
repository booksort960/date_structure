#include "Stack_array.h"
void InitStack(STstack* st)//栈的初始化
{
	st->top = 0;
	st->arr = (STData*)malloc(CAP*sizeof(STData));
	st->capacity = CAP;
}
void StackPush(STstack* st, STData n)//元素入栈
{
	if (st->top == st->capacity)//判断是否需要扩容
	{
		StackExpansion(st);
	}
	st->arr[st->top++] = n;
}
STData StackPop(STstack* st)//元素退栈
{
	assert(st);
	assert(!StackEmpty(st));//判断是否为空栈
	return st->arr[--st->top];
}
int StackEmpty(STstack* st)//判断栈是否为空
{
	if (st->top == 0)
		return 1;
	return 0;
}
void StackDestory(STstack* st)//销毁栈，防止内存泄漏
{
	free(st->arr);
	st->arr = NULL;
}
void StackExpansion(STstack* st)//扩容
{
	STData* tmp = (STData*)realloc((STData*)st->arr, sizeof(STData) * (st->capacity) * 2);
	if (tmp == NULL)
	{
		printf("Exparsion Error\n");
		exit(-1);
	}
	st->arr = tmp;
	st->capacity *= 2;
}
void StackPrint(STstack* st)//打印栈的元素，但前提是要退栈才能得到元素
{
	while(st->top)
	{
		STData ret = StackPop(st);
		printf("%d ", ret);
	}
}