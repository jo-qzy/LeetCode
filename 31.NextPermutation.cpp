class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		bool flag = false;
		int i = 0, j = 0;
		//找到一对i和j，当nums[j]的值大于nums[i]的值，则交换，对其后数字进行排序
		for (i = nums.size() - 1; i >= 0; i--)
		{
			for (j = nums.size() - 1; j > i; j--)
			{
				if (nums[i] < nums[j])
				{
					swap(nums[i], nums[j]);
					sort(nums.begin() + i + 1, nums.end());
					return;
				}
			}
		}
		//当前数字组合已经最大，直接排序
		sort(nums.begin(), nums.end());
	}
};