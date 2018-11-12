//杨辉三角，没啥好说的
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		if (numRows <= 0)
			return vector<vector<int>>();
		vector<vector<int>> ret = { {1} };
		for (int i = 0; i < numRows - 1; i++)
		{
			vector<int> tmp = { 1 };
			for (int j = 0; j < ret[i].size() - 1; j++)
			{
				tmp.push_back(ret[i][j] + ret[i][j + 1]);
			}
			tmp.push_back(1);
			ret.push_back(tmp);
		}
		return ret;
	}
};