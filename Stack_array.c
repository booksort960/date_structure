#include "Stack_array.h"
void InitStack(STstack* st)//ջ�ĳ�ʼ��
{
	st->top = 0;
	st->arr = (STData*)malloc(CAP*sizeof(STData));
	st->capacity = CAP;
}
void StackPush(STstack* st, STData n)//Ԫ����ջ
{
	if (st->top == st->capacity)//�ж��Ƿ���Ҫ����
	{
		StackExpansion(st);
	}
	st->arr[st->top++] = n;
}
STData StackPop(STstack* st)//Ԫ����ջ
{
	assert(st);
	assert(!StackEmpty(st));//�ж��Ƿ�Ϊ��ջ
	return st->arr[--st->top];
}
int StackEmpty(STstack* st)//�ж�ջ�Ƿ�Ϊ��
{
	if (st->top == 0)
		return 1;
	return 0;
}
void StackDestory(STstack* st)//����ջ����ֹ�ڴ�й©
{
	free(st->arr);
	st->arr = NULL;
}
void StackExpansion(STstack* st)//����
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
void StackPrint(STstack* st)//��ӡջ��Ԫ�أ���ǰ����Ҫ��ջ���ܵõ�Ԫ��
{
	while(st->top)
	{
		STData ret = StackPop(st);
		printf("%d ", ret);
	}
}