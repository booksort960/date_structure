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
void initstack(sta* a);//��ʼ��ջ
void pushstack(sta* a,int num);//��ջ
void printstack(sta* a);//��ӡջ
void fullstack(sta* a);//����Ƿ���ջ�����
void emptystack(sta* a);//����Ƿ��ջ�����

void popstack(sta*a);//��ջ


