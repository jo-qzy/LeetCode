class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		char check[3][10];
		for (int i = 0; i < board.size(); i++) {
			memset(check, 0, 30);
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] != '.') {
					if (check[0][board[i][j] - '0'] != 0)
						return false;
					check[0][board[i][j] - '0'] = 1;
				}
				if (board[j][i] != '.') {
					if (check[1][board[j][i] - '0'] != 0)
						return false;
					check[1][board[j][i] - '0'] = 1;
				}
				if (board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] != '.') {
					if (check[2][board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] - '0'] != 0)
						return false;
					check[2][board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] - '0'] = 1;
				}
			}
		}
		return true;
	}
};