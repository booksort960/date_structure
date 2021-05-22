//��������
// 
// 
//����ȡ���Ż�
int GetMid(int* arr, int left, int right)
{
	int mid = (left + right) >> 1;
	int midIndex = arr[left] > arr[mid] ?
		(arr[mid] > arr[right] ? mid : (arr[right] > arr[left] ? left : right)) :
		(arr[left] > arr[right] ? left : (arr[mid] > arr[right] ? right : mid));
	return midIndex;
}
//����ָ�뷨
void BenchmarkDivide(int* arr, int left, int right)
{
	//left�����Ҵ��ڻ�׼ֵ��
	//right������С�ڻ�׼ֵ��
	//��left�ĵ�һ��Ԫ��Ϊ��׼ֵ�����ұ�����
	int end = right, start = left;
	if (left >= right)
		return;
	int midIndex = GetMid(arr, start, end);//����ȡ���Ż� 
	swap(&arr[midIndex], &arr[left]);
	int pivot = left;
	while (left < right)
	{
		while (left < right && arr[right] >= arr[pivot])
			right--;
		while (left < right && arr[left] <= arr[pivot])
			left++;
		swap(&arr[right], &arr[left]);
	}
	int mid = left;
	swap(&arr[pivot], &arr[mid]);
	BenchmarkDivide(arr, start, mid - 1);
	BenchmarkDivide(arr, mid + 1, end);
}


//�ڿӷ�
void DigHoleMethod(int* arr, int left, int right)
{
	int end = right, start = left;
	if (left >= right)
		return;
	int midIndex = GetMid(arr, start, end);//����ȡ���Ż� 
	swap(&arr[midIndex], &arr[left]);
	int key = arr[left];
	int hole = left;
	//��һ��ʼ�����
	while (left < right)
	{
		while (left < right && arr[right] >= key)
			right--;

		arr[hole] = arr[right];
		hole = right;
		while (left < right && arr[left] <= key)
			left++;
		arr[hole] = arr[left];
		hole = left;
	}
	arr[hole] = key;
	DigHoleMethod(arr, start, hole - 1);
	DigHoleMethod(arr, hole + 1, end);
}

//ǰ��ָ�뷨
void FaBPointer(int* arr, int left, int right)
{
	int start = left, end = right;
	if (start >= end)
		return;
	int midIndex = GetMid(arr, start, end);//����ȡ���Ż� 
	swap(&arr[midIndex], &arr[start]);
	int prev = left;
	int key = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (arr[cur] < arr[key] && ++prev != cur)
		{
			swap(&arr[cur], &arr[prev]);
		}
		cur++;
	}
	swap(&arr[prev], &arr[key]);
	FaBPointer(arr, start, prev - 1);
	FaBPointer(arr, prev + 1, right);
}


void QuickSortFirst(int* arr, int len)
{
	//����ָ�뷨��hoare�汾
	//BenchmarkDivide(arr, 0, len - 1);

	//�ڶ���
	//DigHoleMethod(arr, 0, len - 1);

	//ǰ��ָ�뷨
	FaBPointer(arr, 0, len - 1);
}
