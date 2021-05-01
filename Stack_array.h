#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define CAP 4
typedef int STData;
typedef struct Stack//结构体用于维护栈
{
	int top;//栈顶标记
	STData* arr;//栈的指针
	int capacity;//栈的容量
}STstack;
void InitStack(STstack* st);//栈的初始化
void StackPush(STstack* st, STData n);//元素入栈
STData StackPop(STstack* st);//元素退栈
void StackExpansion(STstack* st);//扩容
int StackEmpty(STstack* st);//判断栈是否为空
void StackDestory(STstack* st);//销毁栈，防止内存泄漏
void StackPrint(STstack* st);//打印栈的元素，但前提是要退栈才能得到元素