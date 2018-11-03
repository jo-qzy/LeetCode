class Solution {
public:
	string reverseString(string s) {
		string::iterator left = s.begin();
		string::iterator right = s.end() - 1;
		//第一个条件判断奇数个字符，第二个条件判断偶数个字符
		while (left != right && right + 1 != left)
		{
			swap(*left, *right);
			left++, right--;
		}
		return s;
	}
};