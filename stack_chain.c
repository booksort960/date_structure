#include "stack_chain.h"
void initstack(sta* a)//��ʼ��ջ
{
	top= NULL;
}
void pushstack(sta* a, int num)//��ջ
{
	sta* p = (sta*)malloc(sizeof(sta));
	p->n = num;//�½ڵ㸳ֵ
	p->point = top;
	top = p;
}
int popstack(sta* a)//��ջ
{
	emptystack(a);//����Ƿ��ջ�����

	int date;
	sta* des = top;
	top = top->point;
	date = des->n;
	free(des);
	des = NULL;
	return date;
}
void emptystack(sta* a)//����Ƿ��ջ�����
{
	if (top == NULL || top->point == NULL)
	{
		printf("Stack empty");
		exit(0);
	}
}

