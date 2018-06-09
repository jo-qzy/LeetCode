int removeDuplicates(int* nums, int numsSize) {
	int size = numsSize;
	int slow = 0, fast =1;
	while (fast < numsSize)
	{
		//慢指针每次只走一步，快指针找同慢指针不同的数，直接替换到慢指针后面的位置
		while(nums[slow] == nums[fast] && fast < numsSize)
		{
			fast++;
			size--;
		}
		nums[++slow] = nums[fast++];
	}
	return size;
}
