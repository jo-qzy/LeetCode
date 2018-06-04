class Solution {
public:
	bool isMatch(string s, string p) {
		string::iterator is = s.begin(), ip = p.begin();
		if (is == s.end() && ip == p.end())
		{
			//匹配到结尾，成功
			return true;
		}
		if (is != s.end() && ip == p.end())
		{
			//s未到结尾，p已经没有字符，不匹配
			return false;
		}
		//条件判断没有ip + 1 != p.end()也能过，但在vs下跑不过
		//考虑有*的情况
		if (ip + 1 != p.end() && ip[1] == '*')
		{
			if (ip[0] == is[0] || (ip[0] == '.' && is != s.end()))
			{
				//如果有*，首字母相同，递归匹配一个字符或者不匹配
				//或者有.，且s未到结尾
				return isMatch(string(is + 1, s.end()), string(ip, p.end())) || isMatch(string(is, s.end()), string(ip + 2, p.end()));
			}
			else
			{
				//字符不同，不匹配
				return isMatch(string(is, s.end()), string(ip + 2, p.end()));
			}
		}
		if (ip[0] == is[0] || (ip[0] == '.' && is != s.end()))
		{
			//走到此处说明没有*，匹配一个字符
			return isMatch(string(is + 1, s.end()), string(ip + 1, p.end()));
		}
		return false;
	}
};