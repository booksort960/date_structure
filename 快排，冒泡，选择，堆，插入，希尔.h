#pragma once
#include <stdio.h>

void PrintArray(int* arr, int length);//打印数组
void swap(int* ele1, int* ele2);//交换两个元素


//插入排序
void InsertSort(int* arr, int length);


//希尔排序
void ShellSort(int* arr, int  len);


//冒泡排序
void BubbleSort(int* arr,int len);


//选择排序
void SelectSort(int* arr,int len);


//堆排序
void HeapSort(int* arr,int len);


//快速排序
void QuickSortFirst(int arr, int len);



