#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef int HeapType;
//һ���ṹ��ά����
typedef struct Heap
{
	HeapType* arr;
	int size;
	int capacity;
}Heap;
void AdjustDown(HeapType* arr, int n, int parent);//���µ����㷨

void HeapInit(Heap* hp, HeapType* arr, int n);//��ʼ���ѣ���ջ�������Ž�����
void HeapDestory(Heap* hp);//���ٶѣ���ֹ�ڴ�й©
void HeapPush(Heap* hp, HeapType n);//Ԫ�ز��룬����������������
HeapType HeapPop(Heap* hp);//Ԫ��ɾ��
void HeapBuildheap(Heap* hp);//������
bool HeapEmpty(Heap* hp);//���Ƿ��п�
bool HeapExpansion(Heap* hp);//�ѵ�����

