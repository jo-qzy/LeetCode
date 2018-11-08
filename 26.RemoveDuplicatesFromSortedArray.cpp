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

//c++
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int fast = 0, slow = 0;
		while (fast != nums.size())
		{
			if (nums[fast] != nums[slow])
				nums[++slow] = nums[fast];
			fast++;
		}
		nums.resize(slow + 1);
		return slow + 1;
	}
};