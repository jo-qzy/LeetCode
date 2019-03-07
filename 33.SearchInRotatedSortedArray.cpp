class Solution {
public:
	int search(vector<int>& nums, int target) {
		return searchPart(nums, target, 0, nums.size() - 1);
	}
private:
	int searchPart(vector<int>& nums, int target, int left, int right) {
		if (left > right)
			return -1;
		int div = (left + right) >> 1;
		if (nums[div] == target)
			return div;
		if (nums[left] > nums[div]) {
			if (nums[right] >= target && nums[div] <= target)
				return searchPart(nums, target, div + 1, right);
			else
				return searchPart(nums, target, left, div - 1);
		}
		else {
			if (nums[left] <= target && nums[div] >= target)
				return searchPart(nums, target, left, div - 1);
			else
				return searchPart(nums, target, div + 1, right);
		}
	}
};