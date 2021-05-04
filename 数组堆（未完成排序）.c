#include "headp_array.h"
void test(void)
{
	Heap hp;
	int arr[] = { 23,54,12,14,12,18,100,17 };
	int len = sizeof(arr) / sizeof(arr[0]);
	/*for(int i=(len-1-1)/2;i>=0;--i)
		AdjustDown(arr, len, i);*/
	HeapInit(&hp, arr, len);
	HeapPush(&hp, 88);
	HeapPush(&hp, 58);
	HeapPush(&hp, 8);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	for (int i = 0; i < hp.size; ++i)
		printf("%d ",hp.arr[i]);
}
int main(void)
{
	test();
	return 0;
}