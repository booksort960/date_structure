#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int lint;
typedef struct doulinked
{
	lint num;
	lint* prev;
	lint* next;
}doulink;
void initlinkedlist(doulink* head);//��ʼ��˫������
void LinkedlistFrontPush(doulink* head, lint n);//ͷ�巨
void LinkedlistBackpush(doulink* head, lint n);//β�巨
void LinkedlistFrontPop(doulink* head);//ͷɾ
void LinkedlistBackPop(doulink* head);//βɾ
void LinkedlistPrint(doulink* head);//��ӡ����
