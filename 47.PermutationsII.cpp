class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> check;// 以下标作为检查依据
        set<vector<int>> ret;
        getPermute(nums, vector<int>(), check, ret);
        return vector<vector<int>>(ret.begin(), ret.end()); 
    }
private:
    void getPermute(vector<int>& nums, vector<int> tmp, unordered_map<int, int>& check, set<vector<int>>& ret)
    {
		// 深度优先搜索，set去重
        if (tmp.size() == nums.size())
        {
            ret.insert(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (check[i] == 0)
            {
                check[i]++;
                tmp.push_back(nums[i]);
                getPermute(nums, tmp, check, ret);
                tmp.pop_back();
                check[i]--;
            }
        }
    }
};