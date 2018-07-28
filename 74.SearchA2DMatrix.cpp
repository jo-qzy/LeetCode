class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = 0;
		int col = 0;
		if (matrix.size() != 0)
			col = matrix[0].size() - 1;
		while (row < matrix.size() && col >= 0)
		{
			//当一列最上面的数仍大于target，说明target不在此列
			while (row < matrix.size() && col >= 0 && matrix[row][col] > target)
				col--;
			//当一行最后一个数仍小于target，说明target不在此行
			while (row < matrix.size() && col >= 0 && matrix[row][col] < target)
				row++;
			//找到返回true
			if (row < matrix.size() && col >= 0 && matrix[row][col] == target)
				return true;
		}
		//没找到返回false
		return false;
	}
};