//执行用时: 8 ms, 在Valid Palindrome的C++提交中击败了97.02% 的用户
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.size() == 0)
			return true;
		string tmp;
		//思路也简单，首先把数字和字母全部取出来，字母如果大写通通转成小写
		//如例子中的"A man, a plan, a canal: Panama"
		//转换后变成"amanaplanacanalpanama"
		for (string::iterator cur = s.begin(); cur != s.end(); cur++)
		{
			if (*cur >= 'A' && *cur <= 'Z')
				tmp += *cur - 'A' + 'a';
			else if ((*cur >= 'a' && *cur <= 'z') || (*cur >= '0' && *cur <= '9'))
				tmp += *cur;
		}
		//前后比较，如果回文肯定在相遇之前都相同
		string::iterator left = tmp.begin(), right = tmp.end() - 1;
		while (left != right && right + 1 != left)
		{
			if (*left != *right)
				return false;
			left++, right--;
		}
		return true;
	}
};