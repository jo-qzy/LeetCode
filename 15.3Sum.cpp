/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
	int i = 0, start = 0;
	int** ret = NULL;//由于要动态返回，也不知道多少组，没有c++方便，干脆等会再申请
	*returnSize = 0;
	int flag = 0;//falg作为去除重复数组标记用
	for (i = 1; i < numsSize; i++)
	{
		//先排序，这里选的是插入排序，为了速度可以选择快排或者归并
		int tmp = nums[i];
		for (start = i - 1; start >= 0; start--)
		{
			if (tmp < nums[start])
			{
				nums[start + 1] = nums[start];
			}
			else
			{
				break;
			}
		}
		nums[start + 1] = tmp;
	}
	i = 0;
	while (nums[i] <= 0)
	{
		//要想结果等于0，必定有一个数小于等于0
		//i固定，找另外两个数
		int start = i + 1;
		int end = numsSize - 1;
		while (start < end)
		{
			//这里我选择的是左右指针法
			if (nums[i] + nums[start] + nums[end] > 0)
			{
				//当三数之和大于0，必定需要其中一个数减少，只能是end左移
				end--;
			}
			else if (nums[i] + nums[start] + nums[end] < 0)
			{
				//结果小于0，需要start右移才有可能和增加
				start++;
			}
			else if (nums[i] + nums[start] + nums[end] == 0)
			{
				if (ret == NULL)
				{
					//为空，直接申请不需要考虑别的，因为是第一组数据
					ret = (int**)malloc(sizeof(int*));
					*ret = (int*)malloc(sizeof(int) * 3);
				}
				else
				{
					//进入此至少有一组数据，由于不能重复，所以得先去重
					for (int x = *returnSize; x > 0; x--)
					{
						//从后往前找，重复的数据必定是相隔不远的
						if (nums[i] == *(*(ret + x) + 0) && nums[start] == *(*(ret + x) + 1) && nums[end] == *(*(ret + x) + 2))
						{
							//有重复，
							flag = 1;
							break;
						}
					}
					if (flag == 0)
					{
						//没有重复就申请空间
						ret = (int**)realloc(ret, sizeof(int*) * ((*returnSize) + 1));
						*(ret + (*returnSize)) = (int*)malloc(sizeof(int) * 3);
					}
				}
				if (flag == 0)
				{
					//没有重复就存储数据
					*(*(ret + (*returnSize)) + 0) = nums[i];
					*(*(ret + (*returnSize)) + 1) = nums[start];
					*(*(ret + (*returnSize)) + 2) = nums[end];
					(*returnSize)++;
				}
				flag = 0;//标记重新置0
				start++;//没找玩，start++找下一组
			}
		}
		i++;//i要继续往后查找
	}
	return ret;
}