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
typedef struct Queue//�ṹ������ά������
{
	queue* Dequeue;//��ͷָ��
	queue* Enqueue;//��βָ��
}QUqueue;
void InitQueue(QUqueue* qu);//ջ�ĳ�ʼ��
void QueuePush(QUqueue* qu, QUData n);//Ԫ�����
QUData QueuePop(QUqueue* qu);//Ԫ�س���
int QueueEmpty(QUqueue* qu);//�ж϶����Ƿ�Ϊ��
void QueueDestory(QUqueue* qu);//���ٶӣ���ֹ�ڴ�й©
void QueuePrint(QUqueue* qu);//��ӡ�����е�Ԫ�أ���ǰ����Ҫ���Ӳ��ܵõ�Ԫ��
