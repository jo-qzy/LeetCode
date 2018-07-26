//解法1：时间复杂度O(n)，空间复杂度O(n)（其实只用了n/32个字节）
class Solution1 {
public:
	int findDuplicate(vector<int>& nums) {
		//典型的位图应用，顺便复习了一下位图
		int * bitmap = (int*)calloc((nums.size() / 32 + 1), sizeof(int));
		for (int i = 0; i < nums.size(); i++)
		{
			if (checkBitmap(bitmap, nums[i]) == true)
			{
				//如果位图里有该数信息，返回该数
				free(bitmap);
				return nums[i];
			}
			//位图里面该数第一次出现，存储该数
			setBitmap(bitmap, nums[i]);
		}
	}

private:
	void setBitmap(int * bitmap, int num)
	{
		//在位图对应位置存储该数
		int sec = num / 32;
		int index = num % 32;
		int cmp = 1 << index;
		*(bitmap + sec) = (*(bitmap + sec)) | cmp;
	}

	bool checkBitmap(int * bitmap, int num)
	{
		//判断是否有该数信息
		int sec = num / 32;
		int index = num % 32;
		int cmp = 1 << index;
		if ((*(bitmap + sec) & cmp) != 0)
			return true;
		else
			return false;
	}
};

//解法2：时间复杂度O(n),空间复杂度O(1)（来自剑指offer）
//其实按照题目要求这种方法是不符的，题目要求不修改数组，但是这种方法很巧，放着学习
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		//将每个数字放到对应的位置上，1放在下标0处，n放在下标n-1处
		//当放的时候发现该位置的数已经是相同数时，说明该数即重复数
		for (int i = 0; i < nums.size(); i++)
		{
			while (nums[i] != i + 1)
			{
				if (nums[nums[i] - 1] == nums[i])
					return i + 1;
				int tmp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = tmp;
			}
		}
	}
};

//解法3：时间复杂度O(nlogn)，空间复杂度O(1)（来自剑指offer）
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		//如果区间1~n之间的数超过n，则说明有重复的数字
		//根据这个规则我们把区间分为两块进行统计，直到找到这个重复数
		int left = 1, right = nums.size() - 1;
		int mid = (left + right) >> 1;
		while (left < right)
		{
			mid = (left + right) >> 1;
			int leftcount = count(nums, left, mid);
			if (leftcount > mid - left + 1)
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}
private:
	int count(vector<int> &nums, int left, int right)
	{
		int ret = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= right && nums[i] >= left)
				ret++;
		}
		return ret;
	}
};