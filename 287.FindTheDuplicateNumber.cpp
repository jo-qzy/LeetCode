class Solution {
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