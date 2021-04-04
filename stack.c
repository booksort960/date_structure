#include "stack.h"
void initstack(sta* a)//��ʼ��ջ
{
	a->capacity = N;
	a->base = (stae*)malloc(sizeof(stae) * (a->capacity));
	a->top = a->base;
}
void emptystack(sta* a)//����Ƿ��ջ�����
{
	if (a->top == a->base)
	{
		printf("Stack Empty\n");
		exit(0);
	}
}
void fullstack(sta* a)//���ջ�����
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
void pushstack(sta* a, int num)//��ջ
{
	fullstack(a);//����Ƿ���ջ�����
	a->top->n = num;
	(a->top)++;
}
void printstack(sta* a)//��ӡջ
{
	for (int i = 0; i < a->top-a->base; i++)
	{
		printf("%d ", (a->base+i)->n);
	}
}
void popstack(sta* a)//��ջ
{
	emptystack(a);//���ջ�Ƿ��ջ�����
	a->top--;
}
