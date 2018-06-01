class Solution {
public:
	int removeElement(vector<int> &nums, int val)
	{
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			//左找要删除的元素，右找不需要删除的元素
			while (left < right && nums[left] != val)
			{
				left++;
			}
			while (right > left && nums[right] == val)
			{
				right--;
			}
			nums[left++] = nums[right];
			nums[right] = val;
		}
		return left - 1;
	}
};