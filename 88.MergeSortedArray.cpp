class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (nums2.size() == 0)
			return;
		nums1.resize(m + n);
		int nums1_index = m - 1, nums2_index = n - 1;
		for (vector<int>::reverse_iterator rit = nums1.rbegin(); rit != nums1.rend(); rit++) {
			if (nums1_index == -1)
				break;
			*rit = nums1[nums1_index] > nums2[nums2_index] ? nums1[nums1_index--] : nums2[nums2_index--];
			if (nums2_index == -1)
				return;
		}
		for (int i = 0; i <= nums2_index; i++)
			nums1[i] = nums2[i];
	}
};