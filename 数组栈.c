#include "Stack_array.h"
void Test1(void)
{
	STstack st;
	InitStack(&st);//��ʼ��ջ
	StackPush(&st, 1);//Ԫ����ջ
	StackPush(&st, 2);//Ԫ����ջ
	StackPush(&st, 3);//Ԫ����ջ
	StackPush(&st, 4);//Ԫ����ջ
	StackPrint(&st);//��ӡջ��Ԫ�أ���ǰ����Ҫ��ջ���ܵõ�Ԫ��
	StackPush(&st, 6);//Ԫ����ջ
	StackPush(&st, 5);//Ԫ����ջ
	StackPrint(&st);//��ӡջ��Ԫ�أ���ǰ����Ҫ��ջ���ܵõ�Ԫ��
	StackDestory(&st);//����ջ����ֹ�ڴ�й©
}
int main(void)
{
	Test1();
	return 0;
}