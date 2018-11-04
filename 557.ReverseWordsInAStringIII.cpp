//执行用时: 20 ms, 在Reverse Words in a String III的C++提交中击败了95.53% 的用户
class Solution {
public:
	string reverseWords(string s) {
		string::iterator left = s.begin();
		string::iterator right;
		while (left != s.end())
		{
			right = left;
			while (right + 1 != s.end() && right[1] != ' ')
				right++;
			reverse(left, right);
			if (right + 1 != s.end())
				left = right + 2;
			else
				return s;
		}
		return s;
	}

	void reverse(string::iterator left, string::iterator right)
	{
		while (left != right && right + 1 != left)
		{
			swap(*right, *left);
			right--, left++;
		}
	}
};