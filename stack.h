#pragma once
#include <stdio.h>
#include <stdlib.h>
#define N 3
typedef struct stackele
{
	int n;
}stae;
typedef struct stactk
{
	stae* top;
	stae ele;
	stae* base;
	int capacity;
}sta;
void initstack(sta* a);//初始化栈
void pushstack(sta* a,int num);//入栈
void printstack(sta* a);//打印栈
void fullstack(sta* a);//检查是否满栈的情况
void emptystack(sta* a);//检查是否空栈的情况

void popstack(sta*a);//出栈


