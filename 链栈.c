#include <stdio.h>
#include "stack_chain.h"
void test()
{
	sta a;
	initstack(&a);//初始化栈
	//checkstack(&a);//检查栈的情况
	pushstack(&a, 1);//入栈
	pushstack(&a, 2);//入栈
	pushstack(&a, 3);//入栈
	pushstack(&a, 4);//入栈
	pushstack(&a, 5);//入栈
	pushstack(&a, 6);//入栈
	popstack(&a);//出栈
	popstack(&a);//出栈
	//printstack(&a);//打印栈

}
int main(void)
{
	test();
}