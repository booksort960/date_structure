#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef int HeapType;
//一个结构体维护堆
typedef struct Heap
{
	HeapType* arr;
	int size;
	int capacity;
}Heap;
void AdjustDown(HeapType* arr, int n, int parent);//向下调整算法

void HeapInit(Heap* hp, HeapType* arr, int n);//初始化堆，将栈中数组存放进堆中
void HeapDestory(Heap* hp);//销毁堆，防止内存泄漏
void HeapPush(Heap* hp, HeapType n);//元素插入，但是是在数组的最后
HeapType HeapPop(Heap* hp);//元素删除
void HeapBuildheap(Heap* hp);//构建堆
bool HeapEmpty(Heap* hp);//堆是否判空
bool HeapExpansion(Heap* hp);//堆的扩容

