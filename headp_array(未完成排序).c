#include "headp_array.h"
void swap(HeapType* ele1, HeapType* ele2)
{
	HeapType tmp = *ele1;
	*ele1 = *ele2;
	*ele2 = tmp;
}
void AdjustDown(HeapType* arr,int n,int parent)//���µ����㷨
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if ((child + 1 < n) && arr[child + 1] < arr[child])//��С��
			++child;
		if (arr[parent] > arr[child])
		{
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapInit(Heap* hp, HeapType* arr, int n)//��ʼ���ѣ���ջ�������Ž�����
{
	hp->arr = (HeapType*)malloc(sizeof(HeapType) * n);
	memmove(hp->arr, arr, 4*n);
	hp->size = n;
	hp->capacity = n;
	HeapBuildheap(hp);//����С��
}

void HeapPush(Heap* hp, HeapType n)//Ԫ�ز��룬����������������
{
	if (hp->size == hp->capacity)
	{
		HeapExpansion(hp);
	}
	hp->arr[hp->size++] = n;
	HeapBuildheap(hp);//����С��
}
HeapType HeapPop(Heap* hp)//Ԫ��ɾ��
{
	HeapType ret = hp->arr[0];
	swap(&hp->arr[0], &hp->arr[hp->size - 1]);
	hp->size--;
	HeapBuildheap(hp);//����С��
}
void HeapBuildheap(Heap* hp)//������
{
	for (int i = (hp->size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->arr, hp->size, i);
	}
}
bool HeapEmpty(Heap* hp)//���Ƿ��п�
{
	if (hp->size == 0)
		return true;
	return false;
}
void HeapDestory(Heap* hp)//���ٶѣ���ֹ�ڴ�й©
{
	free(hp->arr);
	hp->arr = NULL;
	free(hp);
}
bool HeapExpansion(Heap* hp)//�ѵ�����
{
	
	HeapType* tmp = realloc(hp->arr, sizeof(HeapType) * 2 * hp->capacity);
	if (tmp == NULL)
	{
		printf("Realloc Error");
		exit(-1);
	}
	hp->arr = tmp;
	hp->capacity *= 2;
}