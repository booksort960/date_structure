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