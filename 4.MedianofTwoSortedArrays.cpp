int QuickMove(int* arr, int left, int right);//快排思想找中位数
void Swap(int* x1, int * x2);//交换函数

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	//此方法可以找两个无序数组的中位数
	assert(nums1 && nums2);
	int* num;
	int size = nums1Size + nums2Size;
	int div = 0;
	double ret = 0;
	//开辟一个新数组将两数组合二为一
	num = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
	memcpy(num, nums1, sizeof(int) * nums1Size);
	memcpy(num + nums1Size, nums2, sizeof(int) * nums2Size);
	div = QuickMove(num, 0, size - 1);//首先将查找的部分用QuickMove分块
	while (div != size / 2)//不论数个数为奇数还是偶数个，size / 2下标的数均需要找
	{
		if (div < size / 2)
		{
			div = QuickMove(num, div + 1, size - 1);
		}
		else
		{
			div = QuickMove(num, 0, div - 1);
		}
	}
	ret = (double)num[div];
	if (size % 2 == 0)
	{
		//数组个数为偶数，需要找下标为(size - 1) / 2的数，两数相加除以二即中位数
		while (div != (size - 1) / 2)
		{
			if (div < (size - 1) / 2)
			{
				div = QuickMove(num, div + 1, size - 1);
			}
			else
			{
				div = QuickMove(num, 0, div - 1);
			}
		}
		ret += (double)num[div];
		free(num);//释放掉申请的空间，不能忘
		return ret / 2;
	}
	free(num);
	return ret;
}

int QuickMove(int* arr, int left, int right)
{
	//assert(arr && left < right);
	//此处注释部分解释一下，上面部分left有可能会和right相等传进来报错
	//下面部分本来想得到left和right以及mid(数组中间的数)的中位数来作为标准区分快排分区，结果造成死循环
	//int mid = GetMid(arr, left, right);
	//Swap(arr + mid, arr + right);*
	int key = arr[right];
	int fast = left;
	int slow = left - 1;
	while (fast < right)
	{
		if (arr[fast] <= key)
		{
			slow++;
			if (slow != fast)
			{
				Swap(arr + fast, arr + slow);
			}
		}
		fast++;
	}
	slow++;
	Swap(arr + slow, arr + right);
	return slow;
}

void Swap(int* x1, int * x2)
{
	if (x1 == x2)
	{
		return;
	}
	*x1 ^= *x2;
	*x2 ^= *x1;
	*x1 ^= *x2;
}