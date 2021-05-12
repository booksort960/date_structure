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
	//Ԥ����->�ӽ�����
	//��������
	//gap==1���ǲ�������gap>1Ԥ����
	//һ��Ҫ��һ�β������򣬳����ź�����Ԥ�������µ�
	int gap = len;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//��1��Ϊ�˱�֤���һ��һ����1�����������ֱ���˳�
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



//������
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
	//����
	//�����->���µ����㷨
	//�����Ѷ�Ԫ�غ����һ��Ԫ��
	//�����µ���
	
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



//��������
int BenchmarkDivide(int* arr, int left, int right)
{
	//left�����Ҵ��ڻ�׼ֵ��
	//right������С�ڻ�׼ֵ��
	//��left�ĵ�һ��Ԫ��Ϊ��׼ֵ�����ұ�����
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


