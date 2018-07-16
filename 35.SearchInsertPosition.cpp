class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		//怎么都感觉这个题不太像面试题。。。。
		int index = 0;
		for (;index < nums.size(); index++)
		{
			if (nums[index] >= target)
				break;
		}
		return index;
	}
};