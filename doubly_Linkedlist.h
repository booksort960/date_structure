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
void initlinkedlist(doulink* head);//初始化双向链表
void LinkedlistFrontPush(doulink* head, lint n);//头插法
void LinkedlistBackpush(doulink* head, lint n);//尾插法
void LinkedlistFrontPop(doulink* head);//头删
void LinkedlistBackPop(doulink* head);//尾删
void LinkedlistPrint(doulink* head);//打印链表
