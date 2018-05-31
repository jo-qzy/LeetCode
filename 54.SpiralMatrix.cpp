class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> tmp;
		if (matrix.empty())
		{
			//为空，特殊处理
			return tmp;
		}
		int start = 0, row = matrix.size(), col = matrix[0].size();
		int i = 0;
		//说一下我是怎么打印的：
		//正常情况下，打印头到倒数第二个字符，每列均是如此
		//举个例子：
		//1 2 3
		//4 5 6
		//7 8 9
		//打印次序为12,36,98,74,5
		while (start < col && start < row)
		{
			//数组不为空则需要考虑几种情况：
			//1.只有一行的情况
			//2.只有一列的情况
			//3.正常情况
			
			//打印最上面一行
			if (row - 1 == start)
			{
				//如果只剩一行或者数组只有一行了，打印当前行
				for (i = start; i < col; i++)
				{
					tmp.push_back(matrix[start][i]);
				}
			}
			else
			{
				//否则正常打印
				for (i = start; i < col - 1; i++)
				{
					tmp.push_back(matrix[start][i]);
				}
			}
			//打印右边一列
			if (col - 1 == start && col != row)
			{
				//如果只剩一列，且该列不止一个元素，打印整列
				for (i = start; i < row; i++)
				{
					tmp.push_back(matrix[i][col - 1]);
				}
			}
			else if (col - 1 != start)
			{
				for (i = start; i < row - 1; i++)
				{
					tmp.push_back(matrix[i][col - 1]);
				}
			}
			//打印下边一行
			if (row - 1 != start)
			{
				//行数不止一列才打印
				for (i = col - 1; i > start; i--)
				{
					tmp.push_back(matrix[row - 1][i]);
				}
			}
			//打印左边一列
			if (col - 1 != start)
			{
				//列数不止一列才打印
				for (i = row - 1; i > start; i--)
				{
					tmp.push_back(matrix[i][start]);
				}
			}
			start++, row--, col--;
		}
		return tmp;
	}
};