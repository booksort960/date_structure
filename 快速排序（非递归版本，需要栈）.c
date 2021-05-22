//ջ��ͷ�ļ�
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define CAP 4
typedef int STData;
typedef struct Stack//�ṹ������ά��ջ
{
	int top;//ջ�����
	STData* arr;//ջ��ָ��
	int capacity;//ջ������
}STstack;
void InitStack(STstack* st);//ջ�ĳ�ʼ��
void StackPush(STstack* st, STData n);//Ԫ����ջ
STData StackPop(STstack* st);//Ԫ����ջ
void StackExpansion(STstack* st);//����
int StackEmpty(STstack* st);//�ж�ջ�Ƿ�Ϊ��
void StackDestory(STstack* st);//����ջ����ֹ�ڴ�й©
void StackPrint(STstack* st);//��ӡջ��Ԫ�أ���ǰ����Ҫ��ջ���ܵõ�Ԫ��

//ջ��ʵ��
#include "Stack_array.h"
void InitStack(STstack* st)//ջ�ĳ�ʼ��
{
	st->top = 0;
	st->arr = (STData*)malloc(CAP * sizeof(STData));
	st->capacity = CAP;
}
void StackPush(STstack* st, STData n)//Ԫ����ջ
{
	if (st->top == st->capacity)//�ж��Ƿ���Ҫ����
	{
		StackExpansion(st);
	}
	st->arr[st->top++] = n;
}
STData StackPop(STstack* st)//Ԫ����ջ
{
	assert(st);
	assert(!StackEmpty(st));//�ж��Ƿ�Ϊ��ջ
	return st->arr[--st->top];
}
int StackEmpty(STstack* st)//�ж�ջ�Ƿ�Ϊ��
{
	if (st->top == 0)
		return 1;
	return 0;
}
void StackDestory(STstack* st)//����ջ����ֹ�ڴ�й©
{
	free(st->arr);
	st->arr = NULL;
}
void StackExpansion(STstack* st)//����
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
void StackPrint(STstack* st)//��ӡջ��Ԫ�أ���ǰ����Ҫ��ջ���ܵõ�Ԫ��
{
	while (st->top)
	{
		STData ret = StackPop(st);
		printf("%d ", ret);
	}
}


//����ʵ��
int PartSort(int* arr, int left, int right)
{
	int start = left, end = right;
	int midIndex = GetMid(arr, start, end);//����ȡ���Ż� 
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