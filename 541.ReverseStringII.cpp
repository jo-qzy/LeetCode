//执行用时: 4 ms, 在Reverse String II的C++提交中击败了100% 的用户
class Solution {
public:
	string reverseStr(string s, int k) {

		bool check = false;
		string::iterator cur = s.begin();
		while (s.end() - cur >= 2 * k)
		{
			reverse(cur, cur + k - 1);
			cur += 2 * k;
		}
		if (s.end() - cur >= k)
			reverse(cur, cur + k - 1);
		else
			reverse(cur, s.end() - 1);
		return s;
	}
	//不知为何此处加inline会变快，明明类内成员函数都是默认inline的
	//管他呢，加上变快了就加上
	inline void reverse(string::iterator left, string::iterator right)
	{
		while (left != right && right + 1 != left)
		{
			swap(*right, *left);
			right--, left++;
		}
	}
};