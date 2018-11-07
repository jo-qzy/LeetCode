class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int>::iterator cur = nums.begin();
		int ret = 0;
		while (cur != nums.end())
		{
			ret ^= cur[0];
			cur++;
		}
		return ret;
	}
};