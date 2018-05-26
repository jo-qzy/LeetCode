int threeSumClosest(int* nums, int numsSize, int target) {
	int cur = 0;//当前位置
	int sum = 0;
	int ret = 0;
	int diff = INT_MAX;//差值
	int cur_diff = 0;//当前差值
	for (cur = 1; cur < numsSize; cur++)
	{
		int i = 0;
		int tmp = nums[cur];
		for (i = cur - 1; i >= 0; i--)
		{
			if (nums[i] > tmp)
			{
				nums[i + 1] = nums[i];
			}
			else
			{
				break;
			}
		}
		nums[i + 1] = tmp;
	}
	cur = 0;
	while (cur < numsSize - 2)
	{
		//左右指针法，固定一个数，两指针寻找剩余的两数
		int left = cur + 1;
		int right = numsSize - 1;
		while (left < right)
		{
			sum = nums[cur] + nums[left] + nums[right];
			cur_diff = abs(target - sum);//获取当前差值
			if (diff > cur_diff)
			{
				//当前差值小于差值，更新差值和返回值
				ret = sum;
				diff = cur_diff;
			}
			if (sum > target)
			{
				//当和大于目标值，right左移
				right--;
			}
			else
			{
				//当和小于等于目标值，left右移
				left++;
			}
		}
		cur++;
	}
	return ret;
}