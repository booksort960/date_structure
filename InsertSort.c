#include <stdio.h>
void InsertSort(int* arr, int length);
void PrintArray(int* arr, int length);
void swap(int* ele1, int* ele2);
int main(void)   
{
	int arr[] = { 2,4,1,4,1,0,43,654,6342,5,2,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	PrintArray(arr, len);
	printf("\n");
	InsertSort(arr, len);
	PrintArray(arr, len);
	return 0;
}
void swap(int* ele1, int* ele2)
{
	int tmp = *ele1;
	*ele1 = *ele2;
	*ele2 = tmp;
}
void InsertSort(int* arr, int length)
{
	for (int i = 0; i < length-1; ++i)
	{
		int key = i;
		int end = key;
		int num = arr[end+1];
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
		arr[end + 1]=num;
	}
	
}
void PrintArray(int* arr, int length)
{
	for (int i = 0; i < length; i++)
		printf("%d ", arr[i]);
}

