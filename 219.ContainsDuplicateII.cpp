class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> check;
		// 记录前一次这个数出现的下标，下标差小于k就可以
        for (int i = 1; i < nums.size(); i++)
        {
            if (i - check[nums[i]] <= k)
            {
                if (check[nums[i]] != 0 || nums[0] == nums[i])
                    return true;
            }
            check[nums[i]] = i;
        }
        return false;
    }
};