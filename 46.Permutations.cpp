class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		//对nums进行排序，然后参考leetcode的31题找下一个字典序数，直至结束
		//也可以直接找下一个字典序数，当达到最大值，nums变回最小值的排序
		vector<vector<int>> ret;
		sort(nums.begin(), nums.end());
		ret.push_back(nums);
		bool flag = false;
		int size = 1;
		for (int i = 1; i <= nums.size(); i++)
		{
			size *= i;
		}
		while (size--)
		{
			for (int i = nums.size() - 1; i >= 0; i--)
			{
				for (int j = nums.size() - 1; j > i; j--)
				{
					if (nums[j] > nums[i])
					{
						flag = true;
						swap(nums[i], nums[j]);
						sort(nums.begin() + i + 1, nums.end());
						ret.push_back(nums);
						break;
					}
				}
				if (flag == true)
				{
					flag = false;
					break;
				}
			}
		}
		return ret;
	}
};