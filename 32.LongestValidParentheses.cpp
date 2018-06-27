class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> index;
		int max = 0;
		for (int i = 0; i < s.size(); i++)
		{
			//当碰到右括号才有可能存在有效序列，且有左括号与之匹配
			if (s[i] == ')' && index.empty() == false && s[index.back()] == '(')
			{
				//左括号的下标出栈
				index.pop_back();
				if (index.empty() == true)
				{
					//如果序列为空，说明i + 1均为有效序列
					max = i + 1;
				}
				else if (max < i - index.back())
				{
					//index存有效序列开始的下标，与i相差的值为有效序列长度
					max = i - index.back();
				}
			}
			else
			{
				//如果不是右括号或者没有与之匹配的左括号，入栈下标
				index.push_back(i);
			}
		}
		return max;
	}
};