#include "Stack_array.h"
void Test1(void)
{
	STstack st;
	InitStack(&st);//初始化栈
	StackPush(&st, 1);//元素入栈
	StackPush(&st, 2);//元素入栈
	StackPush(&st, 3);//元素入栈
	StackPush(&st, 4);//元素入栈
	StackPrint(&st);//打印栈的元素，但前提是要退栈才能得到元素
	StackPush(&st, 6);//元素入栈
	StackPush(&st, 5);//元素入栈
	StackPrint(&st);//打印栈的元素，但前提是要退栈才能得到元素
	StackDestory(&st);//销毁栈，防止内存泄漏
}
int main(void)
{
	Test1();
	return 0;
}