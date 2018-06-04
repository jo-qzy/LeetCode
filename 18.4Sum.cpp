class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;//返回
        set<vector<int>> s;//去重用
        if (nums.size() < 4)
        {
			//数组长度小于4，返回
            return ret;
        }
        sort(nums.begin(), nums.end());//先排序，左右指针法建立在排序的基础上
		//确定两个数，剩下的两个数左右指针找
        for (int i = 0; i < nums.size() - 3; i++)
        {
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                int left = j + 1, right = nums.size() - 1;
                while (left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
						//找到就放入s，不能直接push_back，会重复
                        s.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++, right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        set<vector<int>>::iterator is = s.begin();
        for (; is != s.end(); is++)
        {
			//从set中取就不会重复
            ret.push_back(*is);
        }
        return ret;
    }
};