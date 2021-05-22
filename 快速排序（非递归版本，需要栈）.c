//栈的头文件
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

//栈的实现
#include "Stack_array.h"
void InitStack(STstack* st)//栈的初始化
{
	st->top = 0;
	st->arr = (STData*)malloc(CAP * sizeof(STData));
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
	while (st->top)
	{
		STData ret = StackPop(st);
		printf("%d ", ret);
	}
}


//具体实现
int PartSort(int* arr, int left, int right)
{
	int start = left, end = right;
	int midIndex = GetMid(arr, start, end);//三数取中优化 
	swap(&arr[midIndex], &arr[start]);
	int prev = left;
	int key = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (arr[cur] < arr[key] && ++prev != cur)
		{
			swap(&arr[cur], &arr[prev]);
		}
		cur++;
	}
	swap(&arr[prev], &arr[key]);
	return prev;
}
void _QuickSortNonRe(int* arr, int left, int right)
{
	STstack tmp;
	InitStack(&tmp);
	StackPush(&tmp, left);
	StackPush(&tmp, right);
	while (!StackEmpty(&tmp))
	{
		int Right = StackPop(&tmp);
		int Left = StackPop(&tmp);
		int keyi = PartSort(arr, Left, Right);
		if (Left < keyi - 1)
		{
			StackPush(&tmp, Left);
			StackPush(&tmp, keyi - 1);
		}
		if (keyi + 1 < Right)
		{
			StackPush(&tmp, keyi + 1);
			StackPush(&tmp, Right);
		}
	}
	StackDestory(&tmp);

}