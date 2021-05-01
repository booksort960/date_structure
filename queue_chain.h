#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define CAP 4
typedef int QUData;
typedef struct queue
{
	QUData data;
	struct queue* next;
}queue;
typedef struct Queue//结构体用于维护队列
{
	queue* Dequeue;//队头指针
	queue* Enqueue;//队尾指针
}QUqueue;
void InitQueue(QUqueue* qu);//栈的初始化
void QueuePush(QUqueue* qu, QUData n);//元素入队
QUData QueuePop(QUqueue* qu);//元素出队
int QueueEmpty(QUqueue* qu);//判断队列是否为空
void QueueDestory(QUqueue* qu);//销毁队，防止内存泄漏
void QueuePrint(QUqueue* qu);//打印队列中的元素，但前提是要出队才能得到元素
