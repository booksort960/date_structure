#include "Sort.h"


void PrintArray(int* arr, int length)
{
	for (int i = 0; i < length; i++)
		printf("%d ", arr[i]);
}

void InsertSort(int* arr, int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		int key = i;
		int end = key;
		int num = arr[end + 1];
		while (end >= 0)
		{
			if (num < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;
		}
		arr[end + 1] = num;
	}

}
void swap(int* ele1, int* ele2)
{
	int tmp = *ele1;
	*ele1 = *ele2;
	*ele2 = tmp;
}


void ShellSort(int* arr, int  len)
{
	//预排序->接近有序
	//插入排序
	//gap==1就是插入排序，gap>1预排序
	//一定要有一次插入排序，彻底排好所有预处理留下的
	int gap = len;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//加1是为了保证最后一次一定是1，结束后可以直接退出
		for (int i = 0; i < len - gap; i++)
		{
			int key = i;
			int end = key;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;
			}
			arr[end + gap] = tmp;

		}
	}
}

void BubbleSort(int* arr, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}



void SelectSort(int* arr, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = i+1; j < len; ++j)
		{
			if (arr[j] < arr[i])
				swap(&arr[j], &arr[i]);
		}
	}
}



//堆排序
void AdjustDown(int* arr, int size, int parent)
{
	int child = 2 * parent + 1;
	while (child < size)
	{
		if ((child+1<size)&&arr[child] < arr[child + 1])
			child++;
		if (arr[parent] < arr[child])
		{
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
void HeapSort(int* arr, int len)
{
	//升序
	//建大堆->向下调整算法
	//交换堆定元素和最后一个元素
	//再向下调整
	
	for (int a = (len - 1 - 1) / 2; a >= 0; a--)
	{
		AdjustDown(arr, len , a);
	}
	for (int i = len - 1; i >= 0; i--)
	{
		int end = i;
		swap(&arr[end], &arr[0]);
		for (int j = (end-1-1) / 2; j >= 0; --j)
		{
			AdjustDown(arr, end , j);
		}
		
	}
}



//快速排序
int BenchmarkDivide(int* arr, int left, int right)
{
	//left负责找大于基准值的
	//right负责找小于基准值的
	//以left的第一个元素为基准值，则右边先走
	int end = right, start = left;
	if (left >= right)
		return;
	int pivot = left;
	while (left < right)
	{
		while (left<right&&arr[right] >= arr[pivot])
			right--;
		while (left<right&&arr[left] <= arr[pivot])
			left++;
		swap(&arr[right], &arr[left]);
	}
	int mid = left;
	swap(&arr[pivot], &arr[mid]);
	BenchmarkDivide(arr, start, mid - 1);
	BenchmarkDivide(arr, mid+1, end);
}
void QuickSortFirst(int arr, int len)
{
	BenchmarkDivide(arr, 0, len - 1);
}


