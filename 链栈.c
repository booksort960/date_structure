#include <stdio.h>
#include "stack_chain.h"
void test()
{
	sta a;
	initstack(&a);//��ʼ��ջ
	//checkstack(&a);//���ջ�����
	pushstack(&a, 1);//��ջ
	pushstack(&a, 2);//��ջ
	pushstack(&a, 3);//��ջ
	pushstack(&a, 4);//��ջ
	pushstack(&a, 5);//��ջ
	pushstack(&a, 6);//��ջ
	popstack(&a);//��ջ
	popstack(&a);//��ջ
	//printstack(&a);//��ӡջ

}
int main(void)
{
	test();
}